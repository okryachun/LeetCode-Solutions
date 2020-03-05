#include <stdbool.h>
#include <stdio.h>

int lengthOfLongestSubstring(char * s){
    int head = 0, tail = 0, x = 0, curlen = 0, maxlen = 0, pos = 0;
    bool present = false;

    while(s[head] != '\0') {  //loop through the list
        present = false;    //reset the present flag each iteration
        for(x = tail; x < head; x++) {  //loop from tail to char before head
                                       //checking if new head exists between tail and old head
            if(s[x] == s[head]) {
                present = true;     //if head does exist, set the present flag
                break;
            }
        }
        pos = x;
        if(present) {
            maxlen = curlen > maxlen ? curlen : maxlen; //update maxlen value
            tail = pos + 1; //reset tail relative to when the duplicated character was found
        }
        head++;
        curlen = head - tail;   //update curlen
    }
    return maxlen > curlen ? maxlen : curlen;
}

int main(int argc, char *argv[]) {

    if(argc > 1)
        printf("Longest substring: %d\n", lengthOfLongestSubstring(argv[1]));
    return 0;
}
