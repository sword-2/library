/** @defgroup VerseCompare The Verse Compare (VC) Group
 * The VC group compares a Gutenberg and biblegateway verse
 * @{
 */


/** @brief summary for
  Compares a Gutenberg kjv verses on the local repo to the same one from biblegateway 
The tests
	1. Direct comparison over whole string. If same, done
		2. Length comparison.
			3. Make a lowercase version of each verse
				4. compare lowercase versions
					*If different, report unknown difference
					*If same, split all words and compare them individually.

*/

#include <iostream>
#include <fstream> //?for named pipe?
#include <sstream>
#include <string>
#include <vector>

//debugging
	#include <cerrno> //errno
	#include <cstring> //strerror() which convert errno to a message


/** @brief function in group VC */
void tokenize(std::string *in, const char *delim, std::vector<std::string> *out) {
	std::string err; //starts out as empty string when nothing to retrn 

    out->clear();
    bool delimFirst = false;
	//bool delimLast = false; //leading and trailing delimiter can alter output
	if (in->size() == 0) {
		return; //nothing out, avoid processing below
	}
	else if (in->size() == 1) {
	  if (in->front() == *delim) delimFirst=true;
	  out->push_back(std::string(&in->at(0))); //compiler accepted this longer statement
	} else if (in->size() > 1 ) {
	  if (in->front() == *delim) delimFirst=true;
		//if (in->back() == *delim) delimLast=true; 
		std::stringstream ss(*in);
		std::string substr;
		//while (ss.good()) {
		while(getline(ss, substr, *delim)) {
			//if (substr.size() !=0) 
			out->push_back(substr);
			substr.clear();
      } //end while
	}
	/** remove any extra elements from leading and trailing delimeter */
	if (delimFirst == true) out->erase(out->begin());
	//if (delimLast == true) out->erase(out->end());
	return;
} //end tokenize()


/** global variables */
	std::string msg;
	std::fstream named_pipe;
	std::vector<std::string> verses;
	std::string versesLcI, versesLcBg; //Lc=lowercase
	std::vector<std::string> versesVi, versesVbg; //V=vector
	std::string nl("\n"); std::string tab("\t"); 
	std::string file(__FILE__); std::string comma(",");
	const char space = ' ';

int main(int argc, char **argv) {
try {
	//std::cout << "\n" << __FILE__ << ", starting right after main()." << std::flush;

	if (argc != 2) {
		msg = std::string("ERROR, argc != 2, thus not opening named pipe.") + std::string(" Instead argc=") + std::to_string(argc);
		throw (msg);
	}
	std::string nmedPipe = argv[1];

	std::string line;
	named_pipe.open(nmedPipe); //argv[1]

	if (!named_pipe.is_open()) {
		msg = std::string("\n") + std::string(__FILE__) + std::string(", ERROR: named_pipe not opened. The pipe name sent in was argv[1]=") + std::string(argv[1]) + std::string("; and nmedPipe=") + nmedPipe;
		throw(msg);
	}

	//first verse to be internal (Gutenberg) and second to be biblegateway.
	int counter1=0;
	while(std::getline(named_pipe, line)) { //trouble determining end of input
		//std::cout << "\n" << __FILE__ << " while loop just read line: " << line; 
		verses.push_back(line);
		counter1++;
		if (counter1 == 2) break; //expect up to 2 verses
	}

	//error checking
	if (verses.size() != 2) {
		msg = std::string("\nERROR, did not receive 2 verses. Instead verses.size()=") + std::to_string(verses.size());
		throw(msg);
	}



	//msg = std::string("about to do comparisons...");
	//std::cout << std::string("about to do comparisons...") << std::endl;

	//Direct comparison over whole string. If same, work is done
	if (verses[0].compare(verses[1]) != 0) {
		//some mismatch, extent unknown 
		msg += std::string(" different");
		//std::cout << "; different" << std::flush;
		if (verses[0].length() == verses[1].length()) {
			msg += std::string(", length same at ") + std::to_string(verses[0].length());
			//std::cout << ", length same at " << verses[0].length() << std::flush;
			//See if content is the same in lowercase i.e. Lord vs LORD.
			//std::cout << "\nabout t change to lowercase..." << std::flush;

			for(size_t i=0; i < verses[0].length(); i++ ) {
				versesLcI.push_back(tolower(verses[0].at(i)));
				versesLcBg.push_back(tolower(verses[1].at(i)));
			 }
			//std::cout << "\ncompleted change to lowercase..." << std::flush;
 
	          if (versesLcI.compare(versesLcBg) != 0) { 
				//content mismatch, not just a case mismatch
				//std::cout << "\nsame words..." << std::flush;
				msg += std::string(", unknown difference: ");
				msg += std::string(" Gutenberg (length=") + std::to_string(verses[0].length()) + std::string("): ") + verses[0];
				msg += std::string("; Biblegateway (length=") + std::to_string(verses[1].length()) + std::string("): ") + verses[1];
			} else { 
				//std::cout << "\ndifferent words, before tokenize" << std::flush;
				msg += std::string("; different word(s):");
				//cycle thru the words to output which are different

				tokenize(&verses[0], &space, &versesVi);
				tokenize(&verses[1], &space, &versesVbg);
				//std::cout << "\nafter tokenize..." << std::flush;
				if ( versesVi.size() > 0 ) {
					if (versesVi.size() != versesVbg.size()) {
						msg += std::string("; versesVi.size()=") + std::to_string(versesVi.size()) + std::string(" != versesVbg.size()=") + std::to_string(versesVbg.size()) + std::string("; and the verses were: ") + verses[0] + comma + verses[1];
						throw(msg);
					}
					else {
						for (size_t k=0; k < versesVi.size(); k++ ) {
				    		//std::clog << "\nnot doing the compare.";
	                			if (versesVi[k].compare(versesVbg[k]) != 0) {
					 		msg += std::string(" (") + versesVi[k] + std::string(" - ") + versesVbg[k] + std::string(")");
						}
					} //end else
				  } //end for
				} else {
					//std::cout << " no size/empty content." << std::flush;
					msg += std::string(" no size/empty content.");
				}
			  }
            } else {
	          msg += std::string(", lengths different; "); 
			//std::cout << ", lengths different; " << std::flush; 
			  msg += std::string(" Gutenberg (length=") + std::to_string(verses[0].length()) + std::string("): ") + verses[0];
		      msg += std::string("; Biblegateway (length=") + std::to_string(verses[1].length()) + std::string("): ")+ verses[1];
		    }
	      } else { //verses matched, message not necessary.
            msg = std::string("-");
		  } //else ok, just goto the next verse
	std::cout << msg << std::flush; 
  return(0);
  } //end try
  catch (std::string &msg2) { msg2 = std::string(__FILE__) + msg2; std::cout << msg2 << std::flush; return(1); } 
  catch (std::exception &e) { std::string msg2 = std::string(__FILE__) + std::string(" ") + e.what(); std::cout << msg2 << std::flush; return(1); }
  catch (...) { std::string msg2 = std::string(__FILE__) + std::string(" ") + std::strerror(errno); std::cout << msg2 << std::flush; return(1); }

} //end main

/** @} */ //end of group VC

#ifndef SKIP
#endif
