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

folder = dict()
pastas = list()

for comando in comandos:
    tipoComando = tipoDeComando(comando) 
    comando = comando.removesuffix('\n')

    if tipoComando == 1:
        chave = comando[5:]
    elif tipoComando == 3:
        chave = comando[5:]
    elif tipoComando == 4:
        if chave not in folder.keys(): folder[chave] = list()
    elif tipoComando == 0:
        folder[chave].append(comando)

for key in folder:
    pastas.append(key)

while (len(pastas) > 0):
    for key in folder.keys():
        if type(folder[key]) == list:
            naoTemPastas = True
            soma = 0
            for arquivo in folder[key]:
                if "dir " in arquivo:
                    pasta = arquivo[4:]
                    print(pasta)
                    if  pasta in pastas:
                        naoTemPastas = False
                    else:
                        soma += folder[pasta]
                else:
                    soma += int(arquivo.split()[0])
            if naoTemPastas:
                pastas.remove(key)
                folder[key] = soma

print(pastas)
print(folder)
