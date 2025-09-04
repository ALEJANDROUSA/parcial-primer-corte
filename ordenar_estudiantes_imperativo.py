from typing import List, Tuple

Est = Tuple[str, float]

def mejor_que(a: Est, b: Est) -> bool:
    nota_a, nota_b = a[1], b[1]
    if nota_a != nota_b:
        return nota_a > nota_b
    return a[0] < b[0]

def insertion_sort_estudiantes(arr: List[Est]) -> None:
    for i in range(1, len(arr)):
        key = arr[i]
        j = i - 1
        while j >= 0 and not mejor_que(arr[j], key):
            arr[j + 1] = arr[j]
            j -= 1
        arr[j + 1] = key

def main():
    estudiantes: List[Est] = [
        ("Ana", 4.5),
        ("Luis", 5.0),
        ("Lucia", 5.0),
        ("Bruno", 3.8),
        ("Ana", 5.0)
    ]
    insertion_sort_estudiantes(estudiantes)
    print("Lista ordenada (nota desc, nombre asc en empate):")
    print(estudiantes)

if __name__ == "__main__":
    main()
