# Game of life

Implementacja gry w życie Johna Conwaya

### Kod źródłowy

<https://github.com/mateuszkojro/ui4-game-of-life>

### Dokumentacja

<https://mateuszkojro.github.io/ui4-game-of-life/>

## Wymagania

Aby skompilowac projekt wymagany jest przynajmniej standerd **C++ 14**

---

## Budowa

Program sklada sie z:

- Interfejs prostego API silnika graficznego (`Renderer.h`) i jego implementacja w postacji prostego renderera do
  wyswietlania w konsoli (`SimpleConsoleRenderer.h`)

- Interfejs prostego API silnika gier (`GameEngine.h`) i jego implementacja w postaci tematycznej Gry w
  zycie (`GameOfLife.h`)

## Zalozenia

W zalozeniu kazda gra stworzona z pomoca API `GameEngine` i `Renderer` powinna umozliwiac w prosty sposob zmiane silnika
implementacje silnika graficznego moze to byc osiagniete implementujac wszystkie funckcje interfejsu `Renderer`. A
nastepnie przekazujac wskaznik na instancje zaimplementowanego silnika do konfiguracji silnika gry np:

```cpp
GameEngine::Config config;
config.renderer = new SimpleConsoleRenderer;
GameOfLife game_of_life(board, config);
```

gdzie `SimpleConsoleRenderer` to klasa dziedziczaca po `Renderer`

## Mozliwa konfiguracja

Istnieje mozliwosc ustawienia poczatkowego stanu planszy za pomocą funkcjonalnosci udostepnionych przez klase `Board`:

1. Zapisywanie i odczytywanie stanu planszy z pliku:

```cpp
    // mozemy otworzyc wczesniej zapisana plansze
const char[] PATH = "saved_board.data";
auto saved_board = Board::load_board(PATH);

// ustawiamy komurke na adresie x=1, y=1 jako aktywna
saved_board(1, 1) = true;

// Zapisujemy wprowadzone dane
Board::save_board(saved_board, "new_board.data")

```

2. Ustawienie zawartosci planszy za pomoca tablicy wartosci boolowskich gdzie `true` znaczy ze komurka bedzie zywa
   a `false` ze martwa
   
```cpp
    
    const size_x = 20, size_y = 20;

    auto data = new bool[size_x * size_y];

    memset(data, true, size_x * size_y);

    data[11] = true;
    data[12] = true;
    data[13] = true;

    Board board(data, size_x, size_y);

```
