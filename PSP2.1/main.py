import calc

def main():
    inputs = list(map(float, input("Valores de p e dof: ").split(' ')))
    print(f'x = {calc.estimate_x(float(inputs[0]), float(inputs[1]), 10, 0.0000000001)}')

if __name__ == '__main__':
    main()