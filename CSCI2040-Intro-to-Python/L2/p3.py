def fibo(x1, x2):
    if x2 > 1000:
        return x2
        
    value = fibo(x2, x1 + x2)
    
    return value
