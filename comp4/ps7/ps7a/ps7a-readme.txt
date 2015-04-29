/**********************************************************************
 *  readme.txt template                                                   
 *  Kronos PS7a startup
 **********************************************************************/

Name:
Angel Calcano

Hours to complete assignment (optional):
20


/**********************************************************************
 *  Did you complete the whole assignment?
 *  Successfully or not? 
 *  Indicate which parts you think are working, and describe
 *    how you know that they're working.
 **********************************************************************/
I did not complete the whole assignment. I went back to do more work on it 
since I had seen I read the directions wrong it almost works. 

Eventually I completed the assignment. I had a lot of wierd errors. 

Such as I couldnt create files that didnt exist: aparatleay you have to use
outfile.open("file.txt",fstream::out) in order for it to work. I was only using 
outfile.open("file.txt").

the fail boot kept trying to calculate an successful boot from another successful boot: figured out why I had an if then else based on if a another start up boost was found before a completed boot. 

Another problem I ran in to was that for each line number it kept concatinating in a string in printing out. I fixed this by clearing out the ostringstream variable since I was using it to conver an int in to a string. 


/**********************************************************************
 *  Copy here all regex's you created for parsing the file, 
 *  and explain individually what each ones does.
 **********************************************************************/
(?:(?:([01]?\\d|2[0-3]):)?([0-5]?\\d):)?([0-5]?\\d)$";
[0-9]{4}-(0[1-9]|1[0-2])-(0[1-9]|[1-2][0-9]|3[0-1]).";
"([01][0-9]|2[0-3]):([0-5][0-9]):([0-5][0-9])(?:\\.([0-9]{1,4}))?";
tried using these to get the date with and with out mm and they didn't work. 



after  I went back to do more work I used the following 
 rs = ".*log.c.166.*";
  rsa = ".*oejs.AbstractConnector:Started SelectChannelConnector.*";
  string t = "(\\d{2}):(\\d{2}):(\\d{2})";
  //(\d{2}):(\d{2}):(\d{2})
  string tmm= "(\\d{2}):(\\d{2}):(\\d{2})\\.(\\d{3})";
  //(\d{2}):(\d{2}):(\d{2})\.(\d{3})
  string gd = "(\\d{4})-(\\d{2})-(\\d{2})";

/**********************************************************************
 *  Describe your overall approach for solving the problem.
 *  100-200 words.
 **********************************************************************/
I was going to try to look for each starting point based on log.c.(166) but what I used 
wasnt working. since I spent alot of time trying to get it to work I ended up being three
days late and decided to give up/ 


/**********************************************************************
 *  List whatever help (if any) you received from lab TAs,
 *  classmates, or anyone else.
 **********************************************************************/
Didnt get any help, I used some code from the discussion to see the difference between
my regex to a working one. 


/**********************************************************************
 *  Describe any serious problems you encountered.                    
 **********************************************************************/
Understanding the directions, main reason why I passed the assignment in so 
late was because it took me a while to understand what was being asked to do 
and what the requirments were. 

Getting regex to work.


/**********************************************************************
 *  List any other comments here.                                     
 **********************************************************************/


