# Software comments

## 01-lineFrmt.adom and 02-rename.adom   
The purpose was to merge a single lines many of which had separated into fragments on separate lines.   
02-rename.adom moved groups of files which was faster than typing commands one file at a time. The first script outputed new files with a suffic '-mod'. Then the second deleted the original and moved the "-mod" files to replace the originals. 

## verse Statistics
This was the first partial check of content. The program generates a report if an expected verse reference was missed. So there are files describing the expected chapters and verse range for each book. The program simply compares the expected to actual and references.   
This was only a partial check, but did not check the verse content.

## Copyright:
The .adom filename extensions were for ADOM baptist church. The script was actually bash (Bourne again shell)
