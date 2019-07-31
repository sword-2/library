# bible-kjv
It is not complete and not checked to avoid errors.

**Plan**  
It is planned to be a KJV bible accessible by simple file-system. Some extra folders might be added for support material.  

One extra folder has notices from the original Gutenberg file "10.zip" (Reference 1). That particular download was one giant file now being split into smaller parts for random access.   

A specification for bible verses was found, reference 2. This file was modified in a few ways.
First, it was divided up and the parts for each bible book placed into the corresponding folder. The original name brefspec was kept but with 999-prefix.
Second, only about half the spec was divided up. It had more content for specific bible versions or books past Revelation, but the extra was skipped.
Third, a dos2unix program was run after perceiving a different newline had been used from a Windows machine which did not process as expected in Linux (bash) which saw an extra "^M". 

**Caution: accidental errors.**  

While coding, an original purpose was to supply software code the user could run to statistically validate the verses. But in the process, potential anomalies in a software language were perceived.
Therefore the language was switched to a different one that is not as easily user run-able.
When perceiving anomalies, a user agreement was considered to be fair (Pr 2:9). However, this was abandoned upon hearing software and languages already deployed out to global locations, like an orphanage. Any agreement was too late.
Reference(s):  
-1. http://www.gutenberg.org/files/10/   
-2. http://www.crosswire.org/bsisg/brefspec.txt
