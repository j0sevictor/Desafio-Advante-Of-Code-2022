def tipoDeComando(comando):
    if "$ cd /" in comando:
        return 1
    elif "$ cd .." in comando:
        return 2
    elif "$ cd" in comando:
        return 3
    elif "$ ls" in comando:
        return 4
    else:
        return 0

with open("day 7/input.txt", "r") as arquivoTexto:
    comandos = arquivoTexto.readlines()

apontador = 0
chave = ''
folder = dict()
pastas = list()

for comando in comandos:
    tipoComando = tipoDeComando(comando) 
    
    if tipoComando == 1:
        apontador = 0
        pastas.append(comando[5:-1])
        chave = comando[5:-1]
    elif tipoComando == 3:
        apontador += 1
        chave = comando[5:-1]
        if comando not in pastas: pastas.append(comando[5:-1])
    elif tipoComando == 2:
        apontador -= 1
        chave = pastas[-2]
    elif tipoComando == 4:
        if chave not in folder.keys(): folder[chave] = list()
    elif tipoComando == 0:
        folder[chave].append(comando)

for key in folder:
    for i in range(0, len(folder[key])):
        folder[key][i] = folder[key][i].removesuffix('\n')

print(pastas)

for key in folder:
    naoTemPastas = True
    if type(folder[key]) == list:
        for arquivo in folder[key]:
            if "dir" in arquivo and arquivo[4:] in pastas:
                naoTemPastas = False
                break
    else:
        naoTemPastas = False 

    if naoTemPastas:
        soma = 0
        pastas.remove(key)
        for arquivo in folder[key]:
            if "dir" in arquivo:
                soma += folder[arquivo[4:]]
            else:
                soma += int(arquivo.split()[0])
        folder[key] = soma
print(pastas)
print('\n')
print(folder)
