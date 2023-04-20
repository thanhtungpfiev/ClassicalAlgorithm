'''
File: LongestPalindromicSubstring.py
Project: LongestPalindromicSubstring
File Created: Saturday, 19th March 2022 4:08:47 pm
Author: thanhtungpfiev (thanhtungpfiev@gmail.com)
-----
'''
class Solution:
    def isPalindrome(self, s: str, start: int, end: int):
        while (start < end):
            if (s[start] != s[end]):
                return False
            start += 1
            end -= 1
        return True


    def longestPalindrome1(self, s: str) -> str:
        result = ""
        max = 0
        imax = 0
        jmax = 0
        for i in range(len(s)):
            for j in range(i, len(s)):
                if (self.isPalindrome(s, i, j) and (j - i + 1) > max):
                    max = j - i + 1
                    imax = i
                    jmax = j
        result = s[imax : jmax + 1]
        return result

    def longestPalindrome2(self, s: str) -> str:
        result = ""
        max = 0
        imax = 0
        jmax = 0
        for i in range(len(s)):
            for j in range(i, len(s)):
                if ((j - i + 1) > max and self.isPalindrome(s, i, j)):
                    max = j - i + 1
                    imax = i
                    jmax = j
        result = s[imax : jmax + 1]
        return result

    def longestPalindrome3(self, s: str) -> str:
        result = ""
        max = 0
        imax = 0
        jmax = 0
        for i in range(len(s)):
            for j in range(len(s) - 1, i - 1, -1):
                if ((j - i + 1) > max and self.isPalindrome(s, i, j)):
                    max = j - i + 1
                    imax = i
                    jmax = j
        result = s[imax : jmax + 1]
        return result

    def longestPalindrome4(self, s: str) -> str:
        result = ""
        n = len(s)

        if (n == 0):
            return result

        dp = [[False for i in range(n)] for j in range(n)]
        for i in range(n):
            dp[i][i] = True
            if (i == n - 1):
                break
            dp[i][i + 1] = (s[i] == s[i + 1])
        for i in range(n - 2, -1, -1):
            for j in range(i + 2, n):
                dp[i][j] = dp[i + 1][j - 1] and s[i] == s[j]

        max = 0
        imax = 0
        jmax = 0
        for i in range(len(s)):
            for j in range(i, len(s)):
                if ((j - i + 1) > max and dp[i][j]):
                    max = j - i + 1
                    imax = i
                    jmax = j
        result = s[imax : jmax + 1]
        return result

if __name__ == '__main__':
    s = Solution()
    print(s.longestPalindrome4("jcwwnkwiajicysmdueefqjnrokunucidhgkswbgjkkrujkxkxeanrpjvpliomxztalhmvcldnqmkslkprhgtwlnsnygbzdvtdbsdzsdjggzgmhogknpfhtgjmclrkgfqdbiagwrqqcnagosnqrnpapxfrtrhzlyhszdtgkqggmewqmwugrbufiwfvtjhczqgcwpcyjioeacggiwyinpkyxrpxhglrtojgjmmswxnvirfsrbhmpqgjyyagjqfwkqkjkumywvgfutmiwihwnnhbfxcijaoiyxbdnrckexqfhsmmxflaneccyaoqoxfbaylcvvpfafsikebzcdufvhluldguwsmrtjaljpcjestranfrvgvytozxpcvnwquhnsxlmzkehwopgxvifajmrlwqiqylgxibnypxwpkggxevyfoxywfsfpjbzfxxysgxgwxrzkwdqlkrpajlltzqfqshdokibakkhydizsgwbygqulljqmtxkwepitsukwjlrrmsjptwabtlqytprkkuxtqdmptctkfabxsohrfrqvrbjfbppfkpthosveoppiywkkuoasefviegormlqkqlbhnhblkmglxcbszblfipsyumcrjrkrnzplkveznbtdbtlcptgswhiqsjugqrvujkzuwvoxbjremyxqqzxkgerhgtidsefyemtmstsznvgohexdgetqbhrxaomzsamapxhjibfvtbquhowyrwyxthpwvmfyyqsyibemnfbwkddtyoijzwfxhossylygxmnznpegtgvlrsreepkrcdgbujkghrgtsxwlvxrgrqxnvgqkppbkrxjupjfjcsfzepdemaulfetn"))
