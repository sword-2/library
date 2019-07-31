# bible-kjv
It is not complete and not proofread.

**Plan**  
It is planned to be a KJV bible accessible by simple file-system. Some extra folders might be added for support material.  

The content came from a Gutenberg file "10.zip" (Reference 1). That particular download was one giant file. For easier random access, it is being split into smaller parts.   

A specification for bible verses was found, reference 2. This file was modified in a few ways, per appendix 1. Software logic was planned to count the verses by this file.

**Caution: accidental errors.**  

While coding, an original purpose was to supply software code the user could run to statistically see the verses counted. But in the process, potential anomalies in a software language and own code were perceived.
Therefore the language was switched to a bash shell script. A folder was added (99-bash_script) for the script, which is not complete either. It plans to write a file to the bible book folders to report the verse numbers verified. For example, 999-stats.txt.  
While checking, it was noticed the formatting varied. Sometimes 2 verses were in the same line, other times on separate lines.

Reference(s):  
-1. http://www.gutenberg.org/files/10/   
-2. http://www.crosswire.org/bsisg/brefspec.txt  


# Appendix 1 - mods to brefspec file
First, the brefspec file was divided up and the parts for each bible book placed into the corresponding folder. The original name brefspec was kept but with 999-prefix.  
Second, only about half the spec was divided up. It had more content for specific bible versions or books past Revelation, but the extra was skipped.  
Third, a dos2unix program was run on the files because the end of line character was different - an extra ^M at the end. The extra character was not helping the software logic to count verses.   

# Appendix 2 - software change
The original software intended had a lot of good features for other applications. But due to perceived anomalies, a user agreement was begun to be fair (Pr 2:9) about anomalies to potential recipients. However, this was abandoned upon hearing software and languages already deployed out to global locations, like at least one orphanage. So any agreement would be too late, showing after the software already left for new customers.  
