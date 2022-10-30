import calc

def teste_distribuicao():
    # Testes para a fórmula do gamma
    assert calc.gamma(5) == 24
    assert round(calc.gamma(4.5), 5) == 11.63173

    # Teste para a função da distribuição t
    assert round(calc.t_dist(1.1, 9), 5) == 0.20652


def teste_simpson():
    assert round(calc.simpson(1.1, 9, 10, 0.00001), 7) == 0.3500586

teste_distribuicao()
teste_simpson()