/* Angel Zheondre Calcano
* ps5a 
*/

I tested my code with four different test cases. 

The first case creates enables the constructor and makes a vector of 100 items.
Then it checks for an exception for making a bad constructor, and an invalid 
argument. Using Checkthrow and require throw. 

Second case creates a ring buffer of size 3, enqueues 3 numbers into the vector
after that I use boost require for a peek to see if the first value in the vector is equivalent to what the peek function returns. Afterwards I enqueue the vector thrww times and using boost require to check the value being returned is the correct value. Then I use a boost require throw, to throw the exception when I dequeue an empty vector. 

For the third case I test for an exception of enqueueing on a full string buffer.
Last case tests for peeking on an empty string buffer. 

After looking at the memory usage report from valgrind I had a peak of memory been used of 33.42kb at a snapshot 41 out of 71. Then there was a consisntant amount of memory being used after that about 30 kb. 80% of the memory was being used from heap allocation functions, 24% from BOOST excutions, and about 19% from string methods being used. 
