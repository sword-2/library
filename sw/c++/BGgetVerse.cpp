//Modified function from original C/C++ bible app.

//Parse a web page already retrieved by curl from biblegateway for 1 verse.

//Extract verse from curl reponse by dealing with issues like ...
  //1. Verse changes line number between network calls, possibly due to marketing adds. If varying marketing ads between network calls, a longer marketing ad could bump scripture farther down a file than the previous marketing ad, thus changing the line number of scripture.
  //Varying HTML tags within a verse, possibly different prefix and suffix and tags in the middle of the verse.


#include <string>
#include <iostream>
#include <sstream>
//debugging
  #include <cerrno> //errno
  #include <cstring> //strerror() which convert errno to a message

int main() { //was htmlParseBg1v
  std::string err, in, out;
  std::ostringstream in2;
  try {
    out = std::string("\nline not found"); //default output unless updated below
	//expect biblegateway web page from stdin
		in2 << std::cin.rdbuf();
		//Test code
			//out=std::string("\nstdin received was: ") + in2.str(); // + std::string(", and in=") + in;
			//throw(out);
		in = in2.str();

    std::string linePrior("<div class='passage-content passage-class-0'><div class=\"version-KJV result-text-style-normal text-html\">");
    std::string line1;
    int cmp;
    std::stringstream iss2(in);

    //iterate until getting to a line before the verse
    while(getline(iss2, line1, '\n')) {
      if (iss2.eof()) {
        out=std::string("ERROR 0 - eof reached early"); //clog << *out;
		throw(out); //was return false;
      } else {
        cmp = strncmp(line1.c_str(), linePrior.c_str(), linePrior.size());
	    if (cmp == 0)  break; //found expected line
	}
    } //end while
    getline(iss2, line1, '\n'); //hope the verse on this line

    //Remove the prefix which counts in a certain number of brackets
    size_t pos;
    std::string toErase1(">");
    //cout << "\nverse::curlCpp line1 before erase was as follows:\n" << line1;
    for (int ctr1=1; ctr1 <=4; ctr1++) {
      pos = line1.find(toErase1);
      if (pos != std::string::npos) {
	    //cout << "\nfound a >, about to erase ..." << ctr1 << ", pos=" << pos;
        line1.erase(0, pos+1); //add characters, seven (7) for </span> tag
      } else {
        out=std::string("ERROR 1 - an expected prefix not found."); //+ toErase1 + string(". line was as follows:\n") + line1;
		throw(out); //was return false;
      }
    } //end for

    //Remove suffix. Long string search avoids matching on embedded HTML tags
    std::string toErase2("</span></p> <a class=\"full-chap-link\" href=\"/passage/?search=");
    pos = line1.find(toErase2);
    if (pos != std::string::npos) { 
      line1.erase(pos, line1.length()-pos);
      out = line1;
    } else { 
      out=std::string("ERROR 2 - suffix not found"); // + toErase2 + string(". line was as follows:") + line1;
	throw(out); //was return false;
    }

    //try to identify and remove any embedded spans
    size_t pos2;
    std::string front, embeddedWord, back;
    std::string toErase3a("<span");
    std::string toErase3b("</span>");
    while (true) {
      pos = line1.find(toErase3a);
      if (pos != std::string::npos) {
	    pos2=line1.find(toErase3b);
	    if (pos2 != std::string::npos) {
	      front=line1;
	      front.erase(pos, front.length());
		  back=line1;
	      back.erase(0, pos2+7); //?add 7 for characters in </span>

		  embeddedWord=line1;
		  //clog << "\nembeddedWord step 0: " << embeddedWord;
		  embeddedWord.erase(pos2, embeddedWord.length()); //erase end
		  //clog << "\nembeddedWord step 1: " << embeddedWord;
		  embeddedWord.erase(0, pos); //erase beginning of verse
		  //clog << "\nembeddedWord step 2: " << embeddedWord;

		  pos2=embeddedWord.find(">");
		  if (pos2 != std::string::npos) {
		    embeddedWord.erase(0, pos2+1);
		    //clog << "\nembeddedWord step 3: " << embeddedWord;
		  } else {
		    out += std::string("\nERROR 3 - pos2. embeddedWord was:");
		    out += embeddedWord;
		    throw(out); //was return false;
		  }
	
		  //clog << "\nassembling verse: front=" << front; 
		  //clog << "\nback=" << back;
		  line1 = front + embeddedWord + back;
	    } else {
          out += std::string("ERROR 4 - id not find toErase3b");
		  //clog << *out;
		  throw(out); //was return false;
	    }
      } else {
	    break; //done searching for embedded <span> tags
      }
    } //end while
    out=line1;
    //if (out.size() <= 3) {
	//    std::cout << "\nERROR estimated since out.size() <  3";
	//} else {
		//clog << "\nHTMLparser succeeded, returning *out=" << *out;
		std::cout << out;
	//}
    return 0; //found expected prefix and suffix
  } //end try
  catch (std::string &msg) { out = std::string(__FILE__) + msg; std::cout << out; return 1;} 
  catch (std::exception &e) { out = std::string(__FILE__) + e.what(); std::cout << out; return 1;}
  catch (...) { out = std::string(__FILE__) + strerror(errno); std::cout << out; return 1; }

} //end function

#ifndef SKIP

#endif
