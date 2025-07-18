import subprocess
import os

# Configurações
input_folder = r"C:\Users\vlad\OneDrive\Área de Traalho\vscode.yves\.vscode\Teste"
output_file = "resultado_total.out"
executavel = "main2.exe"

# Lista de arquivos .in na pasta Teste
arquivos = [f for f in os.listdir(
    input_folder) if f.startswith("num") and f.endswith(".in")]
arquivos.sort()  # Ordena alfabeticamente

total_selection = 0.0
total_insertion = 0.0

with open(output_file, "w") as out:
    out.write("Resultados da ordenacao\n========================\n\n")

    for arquivo in arquivos:
        caminho = os.path.join(input_folder, arquivo)
        out.write(f"Arquivo: {arquivo}\n")
        print(f"Processando: {arquivo}")

        for metodo in ["selection", "insertion"]:
            comando = [executavel, caminho, metodo]
            resultado = subprocess.run(comando, capture_output=True, text=True)

            # Escreve toda a saída do programa no arquivo
            out.write(resultado.stdout)

            # Procura a linha com "Tempo de ordenacao"
            for linha in resultado.stdout.splitlines():
                if "Tempo de ordenacao" in linha:
                    try:
                        tempo = float(linha.split(":")[1].strip().split()[0])
                        if metodo == "selection":
                            total_selection += tempo
                        else:
                            total_insertion += tempo
                    except:
                        out.write(f"[ERRO ao ler tempo na linha]: {linha}\n")

        out.write("----------------------------\n")

    # Escreve os totais
    out.write(
        f"\nTempo total Selection Sort: {total_selection:.6f} segundos\n")
    out.write(f"Tempo total Insertion Sort: {total_insertion:.6f} segundos\n")

print(f"\n✅ Finalizado. Veja o arquivo: {output_file}")
