# CRITTERFORGE


** lINK PARA APRESENTAÇÃO **
https://www.canva.com/design/DAF08KxycyU/jl9T6zy8Xx95ZI0PT4OtsA/edit?utm_content=DAF08KxycyU&utm_campaign=designshare&utm_medium=link2&utm_source=sharebutton

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

Você pode jogar CRITTERFORGE facilmente fazendo um fork e executando diretamente no Replit.

- **Fazendo um Fork no Replit:**
  1. Acesse o Replit no seguinte link: [Replit CRITTERFORGE](https://replit.com/@ajls/critterforge).
  2. Clique no botão "Fork" no canto superior direito da página para criar uma cópia do projeto no seu perfil do Replit.
  3. Depois de fazer o fork, clique no botão "Run" no arquivo main.c para iniciar o jogo.
 
  
Além da opção de fork diretamente no Replit, você também pode usar o GitHub para clonar o repositório do CRITTERFORGE. Aqui estão as instruções adicionais:

Usando o GitHub:

Clone o Repositório:

Abra o GitHub e acesse o repositório do CRITTERFORGE no seguinte link: Repositório CRITTERFORGE no GitHub.
Clique no botão "Code" e copie o URL fornecido.
No Replit:

No Replit, clique no botão "Create" para criar um novo projeto.
Selecione a opção "Import from GitHub" e cole o URL que você copiou.

**Pokémon Disponíveis:**
1. **Charmander:**
   - Tipo: Fogo

2. **Squirtle:**
   - Tipo: Água

3. **Bulbasaur:**
   - Tipo: Grama

4. **Pikachu:**
   - Tipo: Elétrico

**Principais funções:**
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

Divirta-se explorando o mundo de CRITTERFORGE e mostre suas habilidades de treinador Pokémon neste jogo emocionante!
