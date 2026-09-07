import sys

def main():
    input = sys.stdin.read
    data = input().split()
    
    if len(data) < 2:
        return
        
    s = data[0]
    t = data[1]
    
    target_count = [0] * 26
    window_count = [0] * 26
    
    for ch in t:
        target_count[ord(ch) - ord('a')] += 1
        
    ans = 0
    R = 0
    n = len(s)
    
    for L in range(n):
        while R < n:
            char_idx = ord(s[R]) - ord('a')
            if window_count[char_idx] + 1 > target_count[char_idx]:
                break
            window_count[char_idx] += 1
            R += 1
            
        ans += (R - L)
        window_count[ord(s[L]) - ord('a')] -= 1
        
    print(ans)

if __name__ == '__main__':
    main()
