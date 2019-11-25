def dec_to_bin(n):
    return bin(n).replace('0b', '')

def main():
    vars = int(input('Inserire il numero delle variabili: '));

    minterms = [int(x) for x in input('inserire i minterms: ').split()]
    minterms.sort()

    impl_primi, impl_ess, finzioni = tabella(vars, minterms)
    minterms_categorised = categorize(minterms,vars)

def tabella(vars, minterms):
    impl_primi = []
    funzioni = []

    minterms = [bin(int(x))[2:].zfill(vars) for x in minterms]

    vars.sort()

def categorize(minterms,vars):
    minterms_categorised = {}

	for i in range(vars + 1):
		minterms_categorised[i] = []

	for i in minterms:
		minterms_categorised[i.count('1')].append([i, [int(i, 2)]])

	return minterms_categorised
