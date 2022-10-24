import numpy as np
import math

class Calculos:
    def media_ln(self, vetor):
        soma = 0
        for valor in vetor:
            soma += math.log(valor)
        return soma / len(vetor)
    
    def variancia(self, vetor, media):
        soma = 0
        for valor in vetor:
            soma += math.pow((math.log(valor, math.e) - media), 2)
        return soma / (len(vetor) - 1)

    def desvio_padrao(self, varianca):
        return math.sqrt(varianca)

    def alcance_tamanhos(self, vetor):
        media = self.media_ln(vetor)
        var = self.variancia(vetor, media)
        dp = self.desvio_padrao(var)

        pp = pow(math.e, media - 2*dp)
        p = pow(math.e, media - dp)
        m = pow(math.e, media)
        g = pow(math.e, media + dp)
        gg = pow(math.e, media + 2*dp)

        return pp, p, m, g, gg

def carrega_entrada(arquivo):
    try:
        entrada = np.loadtxt(arquivo).tolist()
    except:
        return False
    return entrada

def separa_loc_por_metodo(partes):
    partes_divididas = []

    for parte in partes:
        if type(parte) != float:
            partes_divididas.append(int(parte[0]) / int(parte[1]))
        else:
            partes_divididas.append(int(parte))
    
    return partes_divididas