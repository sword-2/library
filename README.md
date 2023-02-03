# README

## Why the project is useful? 

n/a - draft content

## What can be done with the project. 

n/a

## How can the project be used? 

n/a

## Comments

The content hopes to eventually be an option to read scriptures like other bibles. It is initially is limited to King James Version (kjv) plain text. The next paragraph touches upon accuracy. When the repo is downloaded, a file manager may enable random access by selecting the the desired bible book and chapter number. The file manager access method initially avoids app installs, software buttons, menus, and training to use the app.

The content for kjv was checked with a shell script (sw/0) to minimize accidental errors. The script loops through all the kjv scriptures in the repo and compares each one to the same verse from biblegateway.com. The shell script comparison was already run, and the results written to the sub-folder sw/99-rpt/
If the verses were the same, the report just puts a hyphen (-). Sometimes the shell script determined there were differences between the same verse for Gutenberg and biblegateway. A lot of the differences were believed to be due to upper/lower case differences changed in html/js/css markup. For example, sometimes the shell script extracted the word 'Lord' from the Gutenberg verse, but biblegateway html/js/css might have a different case 'LORD/Lord'. The shell script only looked at the text and didn't perform html/js/css operations that the biblegateway html/js/css might, thus it just reports a difference.

The shell script uses two C++ programs in the subfolder sw/c++. The make program has to be run to build the code for the local machine so it is available for the shell script.

The network efficiency for the shell script calls to biblegateway was poor. An efficient way was not known to just get a verse -  something like github raw user content would just get content. Each verse required its own network call, and that call had sales advertisements embedded to the page which one C++ function was made to filter all that out to get just the verse.

As mentioned, the scriptures on the repo were copied from a large Gutenberg text file. The file was reformatted by splitting the content to different files, removing windows characters, and removing line breaks that split a verse across multiple lines. Getting one verse per line facilitates easier reading by a computer program.
