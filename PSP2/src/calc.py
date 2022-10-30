import math

def gamma(x: int) -> float:
    if x == 1:
        return 1
    if x == 1/2:
        return math.sqrt(math.pi)
    return ((x - 1) * gamma(x - 1))

def t_dist(x: float, dof: float) -> float:
    return (gamma((dof + 1)/2)) / (math.sqrt(dof * math.pi) * gamma(dof/2)) * ((1 + ((x**2) / dof)) ** (-(dof + 1) / 2))

def p_calc(x: float, dof: float, num_seg: int) -> float:
    p = t_dist(0, dof) + t_dist(x, dof)
    W = x / num_seg

    for i in range(1, num_seg):
        if i % 2 == 0:
            p += 2 * t_dist(i * W, dof)
        else:
            p += 4 * t_dist(i * W, dof)

    return p * (W / 3)
    
def simpson(x: float, dof: float, num_seg: float, E: float) -> float:
    p = 0
    prev_p = math.inf
    ns = num_seg

    while math.fabs(p - prev_p) > E:
        prev_p = p
        p = p_calc(x, dof, ns)
        ns *= 2
    return p