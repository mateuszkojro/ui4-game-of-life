# Game of life

Implementacja gry w życie Johna Conwaya

### Kod źródłowy

<https://github.com/mateuszkojro/ui4_game_of_life>

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

