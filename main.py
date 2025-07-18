import os
import time

def selection_sort(arr):
    n = len(arr)
    for i in range(n-1):
        min_idx = i
        for j in range(i+1, n):
            if arr[j] < arr[min_idx]:
                min_idx = j
        arr[i], arr[min_idx] = arr[min_idx], arr[i]

def insertion_sort(arr):
    n = len(arr)
    for i in range(1, n):
        key = arr[i]
        j = i - 1
        while j >= 0 and arr[j] > key:
            arr[j+1] = arr[j]
            j -= 1
        arr[j+1] = key

def ler_arquivo(nome_arquivo):
    arr = []
    with open(nome_arquivo, "r") as f:
        for linha in f:
            linha = linha.strip()
            if linha:
                try:
                    num = int(linha)
                    arr.append(num)
                except:
                    pass
    return arr

def ordenar_e_tempo(arr, metodo):
    arr_copia = arr.copy()
    start = time.perf_counter()
    if metodo == "selection":
        selection_sort(arr_copia)
    elif metodo == "insertion":
        insertion_sort(arr_copia)
    else:
        raise ValueError("Método inválido")
    end = time.perf_counter()
    tempo = end - start
    return tempo

def main():
    input_folder = "Teste"
    output_file = "resultado_total.out"

    arquivos = [f for f in os.listdir(input_folder) if f.startswith("num") and f.endswith(".in")]
    arquivos.sort()

    total_selection = 0.0
    total_insertion = 0.0

    with open(output_file, "w") as out:
        out.write("Tempos de ordenação\n========================\n\n")
        
        for arquivo in arquivos:
            caminho = os.path.join(input_folder, arquivo)
            print(f"\n Arquivo: {arquivo}")
            out.write(f"Arquivo: {arquivo}\n")

            arr = ler_arquivo(caminho)

            for metodo in ["selection", "insertion"]:
                try:
                    tempo = ordenar_e_tempo(arr, metodo)
                    out.write(f"Metodo: {metodo} | Tempo: {tempo:.6f} segundos\n")
                    print(f"   {metodo.capitalize()} Sort: {tempo:.6f} segundos")

                    if metodo == "selection":
                        total_selection += tempo
                    else:
                        total_insertion += tempo
                except Exception as e:
                    out.write(f"[ERRO]: {str(e)}\n")

            out.write("----------------------------\n")

        # Totais de tempo
        out.write(f"\nTempo total Selection Sort: {total_selection:.6f} segundos\n")
        out.write(f"Tempo total Insertion Sort: {total_insertion:.6f} segundos\n")

   
    print("\n==== Totais ====")
    print(f" Tempo total Selection Sort: {total_selection:.6f} segundos")
    print(f" Tempo total Insertion Sort: {total_insertion:.6f} segundos")
    print(f"\n Finalizado. Veja o arquivo: {output_file}")

if __name__ == "__main__":
    main()
