import calc

def teste1():
    result = calc.estimate_x(0.2, 6, 10, 0.0000000001)
    assert round(result, 5) == 0.55338

def teste2():
    result = calc.estimate_x(0.45, 15, 10, 0.0000000001)
    assert round(result, 5) == 1.75305

def teste3():
    result = calc.estimate_x(0.495, 4, 10, 0.0000000001)
    assert round(result, 5) == 4.60409