# CRITTERFORGE

**Descrição do Jogo:**

CRITTERFORGE é um emocionante jogo desenvolvido em linguagem C, onde dois jogadores têm a oportunidade de escolher entre 4 criaturas místicas para travar batalhas épicas e determinar quem alcançará o melhor score no final. Inspirado no universo Pokémon, o jogo é projetado para ser jogado em turnos, proporcionando uma experiência estratégica e divertida.

**Saiba mais:**

1. **Escolha do Pokémon:**
   - Inicie o jogo escolhendo o seu Pokémon entre as 4 opções disponíveis. Cada criatura tem suas próprias habilidades e estatísticas únicas, então escolha sabiamente.

2. **Batalhas em Turnos:**
   - Os jogadores se enfrentarão em emocionantes batalhas por turnos. Use as habilidades do seu Pokémon com estratégia para derrotar o oponente e ganhar pontos.

3. **Score Final:**
   - Ao final das batalhas, o jogo calculará o score com base no desempenho de cada jogador. Aquele com o score mais alto será coroado como o mestre de CRITTERFORGE!

**Como Rodar o Jogo:**

Você pode jogar CRITTERFORGE facilmente clonando o repositório em sua máquina local usando o Git ou executando diretamente no Replit.

- **Clonando o Repositório:**
  1. Abra seu terminal e digite o seguinte comando:
     ```bash
     git clone https://github.com/ajls/critterforge.git
     ```
  2. Navegue até o diretório do jogo:
     ```bash
     cd critterforge
     ```
  3. Execute o arquivo `main.c` para iniciar o jogo:
     ```bash
     gcc main.c -o critterforge
     ./critterforge
     ```

- **Acesso Direto no Replit:**
  - Clique no seguinte link para acessar e jogar diretamente no Replit: [CRITTERFORGE no Replit](https://replit.com/@ajls/critterforge).
 

**Pokémon Disponíveis:**
1. **Charmander:**
   - Tipo: Fogo

2. **Squirtle:**
   - Tipo: Água

3. **Bulbasaur:**
   - Tipo: Grama

4. **Pikachu:**
   - Tipo: Elétrico


**Principais funções**
**Explicação das Principais Funções:**

1. **`pr_pikachu`, `pr_charmander`, `pr_squirtle`, `pr_bulbasour`:**
   - Estas funções são responsáveis por imprimir na tela a representação gráfica dos Pokémon Pikachu, Charmander, Squirtle e Bulbasaur, respectivamente. Elas utilizam caracteres ASCII para criar a arte ASCII dos Pokémon.

2. **`savePlayerStats`:**
   - Salva as estatísticas de um jogador vencedor em um arquivo chamado "player_stats.dat". Se o arquivo não existir, ele será criado.

3. **`updatePlayerStats`:**
   - Atualiza as estatísticas de um jogador vencedor no arquivo "player_stats.dat". Se o jogador já estiver presente nas estatísticas, incrementa o número de vitórias; caso contrário, adiciona um novo registro.

4. **`comparePlayerStats`:**
   - Função de comparação utilizada para ordenar as estatísticas dos jogadores com base no número de vitórias, usada na função `qsort`.

5. **`loadPlayerStats`:**
   - Carrega as estatísticas dos jogadores do arquivo "player_stats.dat", ordena essas estatísticas com base nas vitórias e as exibe na tela. Dá a opção ao jogador de jogar novamente, visualizar o placar ou sair do jogo.

6. **`getPlayerName`:**
   - Solicita ao jogador que digite seu nome. A função lê os caracteres diretamente com `getchar` para garantir a entrada correta e atualiza a tela conforme o nome é digitado.

7. **`choosePokemon`:**
   - Permite que o jogador escolha seu Pokémon a partir de uma lista. A função exibe as opções na tela e aguarda a entrada do jogador.

8. **`processPlayerInput`:**
   - Processa a entrada do jogador durante a batalha, ajustando a saúde do Pokémon adversário com base no ataque escolhido.

9. **`drawGameOverScreen`:**
   - Exibe a tela de fim de jogo, indicando o vencedor e dando a opção de jogar novamente, visualizar o placar ou sair do jogo.

10. **`drawBattleScreen`:**
    - Desenha a tela de batalha, mostrando a representação gráfica dos Pokémon, informações sobre a batalha e as opções de ataque disponíveis.

11. **`main`:**
    - Função principal do jogo. Inicia o loop principal do jogo, onde os jogadores escolhem seus Pokémon, batalham e o resultado é mostrado. Também gerencia o ciclo de jogo, incluindo as funções de inicialização e destruição dos recursos do jogo.




Divirta-se explorando o mundo de CRITTERFORGE e mostre suas habilidades de treinador Pokémon neste jogo emocionante!
