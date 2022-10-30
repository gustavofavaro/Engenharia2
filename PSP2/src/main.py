import calc

def main():
    inputs = list(map(float, input("Valores de x e dof: ").split(' ')))
    print(f'p = {calc.simpson(inputs[0], inputs[1], 10, 0.00001)}')

if __name__ == '__main__':
    main()