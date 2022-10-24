import utils

def caso_teste1():
    entrada = utils.carrega_entrada('../test/caso_uso1.txt')
    calc = utils.Calculos()
    partes = utils.separa_loc_por_metodo(entrada)
    pp, p, m, g, gg = calc.alcance_tamanhos(partes)

    assert '{:.4f}'.format(pp) == str(4.3953)
    assert '{:.4f}'.format(p) == str(8.5081)
    assert '{:.4f}'.format(m) == str(16.4696)
    assert '{:.4f}'.format(g) == str(31.8811)
    assert '{:.4f}'.format(gg) == str(61.7137)

def caso_teste2():
    entrada = utils.carrega_entrada('../test/caso_uso2.txt')
    calc = utils.Calculos()
    partes = utils.separa_loc_por_metodo(entrada)
    pp, p, m, g, gg = calc.alcance_tamanhos(partes)

    assert '{:.4f}'.format(pp) == str(6.3375)
    assert '{:.4f}'.format(p) == str(8.4393)
    assert '{:.4f}'.format(m) == str(11.2381)
    assert '{:.3f}'.format(g) == str(14.965)
    assert '{:.3f}'.format(gg) == str(19.928)

caso_teste1()
caso_teste2()