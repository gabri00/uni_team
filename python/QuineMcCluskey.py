def dec_to_bin(n):
    return bin(n).replace('0b', '')


n_vars = input('Inserire il numero delle variabili: ');

vars = []

i = 0
while 0 <= i <= 2 ** int(n_vars) - 1:
    bits = input(F'Inserire il minterm {i+1}: ')
    vars.append(dec_to_bin(int(bits)).zfill(int(n_vars)))

    i += 1

vars.sort()

for x in range(2 ** int(n_vars) - 1):
    count = vars[x].count('1')

    if count == 0:
        vars_first = []

print(n_vars)
print(vars)
