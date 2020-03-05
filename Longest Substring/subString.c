
int lengthOfLongestSubstring(char * s){
    int head = 0, tail = 0, x = 0, curlen = 0, maxlen = 0, pos = 0;
    bool present = false;
    
    while(s[head] != '\0') {
        present = false; pos = 0;
        for(x = tail; x < head; x++) {
            if(s[x] == s[head]) {
                present = true;
                break;
            }
        }
        pos = x;
        if(present) {
            maxlen = curlen > maxlen ? curlen : maxlen;
            tail = pos + 1;
        }
        head++;
        curlen = head - tail; 
        
    }                
    return maxlen > curlen ? maxlen : curlen;
}
