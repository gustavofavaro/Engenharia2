import sys
import utils

def main():
    if not sys.argv[1]:
        print('Erro: insira o local do arquivo com a entrada.')
        return False

    entrada = utils.carrega_entrada(sys.argv[1])
    if not entrada:
        print('Erro: arquivo não existe.')
        return False

    calc = utils.Calculos()
    partes = utils.separa_loc_por_metodo(entrada)
    pp, p, m, g, gg = calc.alcance_tamanhos(partes)

    print('PP: {:.4f}'.format(pp))
    print(' P: {:.4f}'.format(p))
    print(' M: {:.4f}'.format(m))
    print(' G: {:.4f}'.format(g))
    print('GG: {:.4f}'.format(gg))

if __name__ == "__main__":
    main()