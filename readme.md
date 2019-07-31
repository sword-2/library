# bible-kjv
It is not complete and not checked to avoid errors.

**Plan**  
It is planned to be a KJV bible accessible by simple file-system. Some extra folders might be added for support material.  

One extra folder has notices from the original Gutenberg file "10.zip" (Reference 1). That particular download was one giant file now being split into smaller parts for random access.   

A specification for bible verses was found, reference 2. This file was modified in a few ways.  
First, it was divided up and the parts for each bible book placed into the corresponding folder. The original name brefspec was kept but with 999-prefix.  
Second, only about half the spec was divided up. It had more content for specific bible versions or books past Revelation, but the extra was skipped.  
Third, a dos2unix program was run on the files because the end of line character was different - an extra ^M at the end.  

**Caution: accidental errors.**  

While coding, an original purpose was to supply software code the user could run to statistically see the verses counted. But in the process, potential anomalies in a software language and own code were perceived.
Therefore the language was switched to a bash shell script. A folder was added (99-bash_script) for the script, which is not complete. It plans to write a file to the bible book folders to report the verse numbers checked or missed.  
A user agreement was considered to be fair (Pr 2:9) about anomalies. However, this was abandoned upon hearing software and languages already deployed out to global locations, like an orphanage. So any agreement would be too late.

Reference(s):  
-1. http://www.gutenberg.org/files/10/   
-2. http://www.crosswire.org/bsisg/brefspec.txt
