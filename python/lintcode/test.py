class Solution:
    """
    @param s: the article
    @return: the number of letters that are illegal
    """
    def count(self, s):
        # Write your code here.
        if not s:
            return 0

        err = 0
        stop = True # True: word should be uppercase
                    # False: word should be lowercase or space
        
        for i in range(len(s)):
            ch = s[i]
            if stop and ch.islower():
                err += 1
            if not stop and ch.isupper():
                err += 1
        
            if ch.isalpha():
                stop = False
            elif ch == '.' or ch.isspace():
                stop = True
            
        print(err)
        return err


s = Solution()
s.count("abc d")
s.count("Mabc C D. abc BIG")