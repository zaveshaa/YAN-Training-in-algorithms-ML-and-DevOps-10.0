import sys

def main():
    input = sys.stdin.read
    data = input().split()
    
    if not data:
        return
        
    n = int(data[0])
    words = data[1:n+1]
    
    for s in words:
        if not s:
            continue
            
        result = [s[0].lower()]
        
        # other symb
        for char in s[1:]:
            if char.isupper():
                result.append('_')
                result.append(char.lower())
            else:
                result.append(char)
                
        print("".join(result))

if __name__ == '__main__':
    main()
