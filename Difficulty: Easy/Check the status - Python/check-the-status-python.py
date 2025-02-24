#{ 
 # Driver Code Starts
#Initial Template for Python 3

# } Driver Code Ends
#User function Template for python3
class Solution:
    def checkStatus(self, a, b, flag):
        if a > 0 or b > 0:
            if (not(a > 0 and b > 0)) and flag == False:
                return True
            else:
                return False
        if a< 0 or b < 0:
            if flag == True:
                return True
            else:
                return False
            
        # code here

#{ 
 # Driver Code Starts.

# Driver Code
def main():
    
    # Testcase input
    testcases = int(input())
    
    # Looping through testcases
    while(testcases > 0):
        a = int(input())
        b = int(input())
        flag = input()
        
        if(flag == "True"):
            flag = True
        else:
            flag = False
        
        if(Solution().checkStatus(a, b, flag) is True):
            print ("True")
        else:
            print ("False")
        
        testcases -= 1
        print("~")
 
if __name__ == '__main__':
    main()
# } Driver Code Ends