int firstUniqChar(char* s) {
    int char_counts[256] = {0}; 
    int len = strlen(s);

    for (int i = 0; i < len; i++) {
        char_counts[s[i]]++;
    }

    for (int i = 0; i < len; i++) {
        if (char_counts[s[i]] == 1) {
            return i;
        }
    }

    return -1; 
    
}