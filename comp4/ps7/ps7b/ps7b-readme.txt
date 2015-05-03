/**********************************************************************
 *  readme.txt template                                                   
 *  PS7b: Kronos log parsing
 **********************************************************************/

Name:
Angel Calcano

Hours to complete assignment (optional):
35

/**********************************************************************
 *  Did you complete the whole assignment?
 *  Successfully or not? 
 *  Indicate which parts you think are working, and describe
 *    how you know that they're working.
 **********************************************************************/
I completed the whole assignment, I know it is working because I compared it to the sample results file. 


/**********************************************************************
 *  Copy here all regex's you created for parsing the file, 
 *  and explain individually what each ones does.
 **********************************************************************/
.*log.c.166.* Will match the start of boot up timing. 
.*oejs.AbstractConnector:Started SelectChannelConnector.* Will find matched string for the completion of the boot up timing.

(\\d{2}):(\\d{2}):(\\d{2}) time hours, mins, seconds and groups each section

(\\d{2}):(\\d{2}):(\\d{2})\\.(\\d{3}) Grabs time hours, mins, seconds, and milliseconds

.*intouch-application-base-.*  Match strings for softload.

.*: removing.* Looks for old version of softload.

(?=-[0-9])(.*?)(?=\\.armv) This will grab the text between base-(  ).arm . 
.*: Processing.* Finds the string for the softload process.
(\\s*\\w{3}\\s*[0-9]{2}) Finds a three letter month, with the number day.
([0-9]{2}):([0-9]{2}):([0-9]{2}) Gets time.
.*(nameofservice).* Finds the start up services
.*Starting Service. (name of service).* Finds march for service.
.*SOFTLOADSERVICE;Install started.* Finds string for when the softload starts.
.*ExitValue from install command : 0.* Will find the strin for when a softload comepltes successfully.
.*Service started successfully.  (name of service).* Finds the matched string for a successful service.
/**********************************************************************
 *  Describe your overall approach for solving the problem.
 *  100-200 words.
 **********************************************************************/
First I looked at the file to look for patterns. I also used notepad++ and an regex website to practice with the regexes. After many trial and error emptepts I started to see
the pattern of how to match the information and how to grab it. I used regex match to match a string with the expression. Then I used regex search to search and grab the peices of information. After I had seen that it was working, I started to design a class that will have this information to organize the code and to make debugging alot easyer.


/**********************************************************************
 *  List whatever help (if any) you received from lab TAs,
 *  classmates, or anyone else.
 **********************************************************************/
Looked online for tutorials, didn't ask for help. Had to read the assignment 
alot of times to understand what I needed to do.


/**********************************************************************
 *  Describe any serious problems you encountered.                    
 **********************************************************************/
Trying to figure out why certain matches wouldn't work. I spent a few hours trying to solve the issue, but apperantly the regex will match when you put *. and .* at the fron and end of the expression.


/**********************************************************************
 *  List any other comments here.                                     
 **********************************************************************/

/**********************************************************************
 *  readme.txt template                                                   
 *  Kronos PS7b complete
 **********************************************************************/

