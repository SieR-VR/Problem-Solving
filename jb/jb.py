p_g = list('15144147335713615298521698039752559130587509428873882069906927167402216790264')
q_g = list('15624342005774166525024608067426557093567392652723175301615422384508274269305')

n = 118641897764566817417551054135914458085151243893181692085585606712347004549784923154978949512746946759125187896834583143236980760760749398862405478042140850200893707709475167551056980474794729592748211827841494511437980466936302569013868048998752111754493558258605042130232239629213049847684412075111663446003

def solve_q(p, q, i):
    p_current = int(''.join(p))
    for digit in range(10):
        temp_q_list = [str(digit)] + q
        temp_q_current = int(''.join(temp_q_list))

        if (p_current * temp_q_current) % (10 ** (i*2 - 1)) == (n % (10 ** (i*2 - 1))):
            solve_p(p, ([] if i == len(p_g) + 1 else [q_g[-i]]) + temp_q_list, i)

def solve_p(p, q, i):
    if i == len(p_g) + 1:
        print(''.join(p), ''.join(q))
        return
    
    q_current = int(''.join(q))
    for digit in range(10):
        temp_p_list = [str(digit)] + p
        temp_p_current = int(''.join(temp_p_list))

        if (q_current * temp_p_current) % (10 ** (i*2)) == (n % (10 ** (i*2))):
            solve_q([p_g[-i]] + temp_p_list, q, i + 1)

solve_q(['3'], [], 1)