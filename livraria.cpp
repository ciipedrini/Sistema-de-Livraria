#include <iostream>
#include <stdio.h>
using namespace std;

FILE *livroArq;

struct obras {
  int ano, codigo;
  char titulo[100];
}; obras obraCad;

void cadastro_livro() {
  system("cls");
  char resposta;
  livroArq = fopen("livros.bin", "ab");
  if (livroArq == NULL) {
      cout << "Erro ao abrir o arquivo\n";
      exit(1);
  }
  do {
      cout << "\n ----------------------------------------\n";
      cout << "\n *** PAGINA DE CADASTRO ***\n";
      cout << "\n ----------------------------------------\n";
      cin.ignore();
      cout << "\nInforme titulo da obra: ";
      cin.getline(obraCad.titulo, 100);
      cout << "\nInforme ano publicado: ";
      cin >> obraCad.ano;
      cout << "\nInforme o codigo da obra: ";
      cin >> obraCad.codigo;

      fwrite(&obraCad, sizeof(obras), 1, livroArq);

      cout << "\nDeseja adicionar mais obras (S/N)? ";
      cin >> resposta;

  } while (resposta == 's' || resposta == 'S');

  fclose(livroArq);

  cout << "\nLivro(s) cadastrado(s) com sucesso!\n";
  system("pause");
}
void mostrar_obras() {
  livroArq = fopen("livros.bin", "rb");
  if (livroArq == NULL) {
      cout << "Erro ao abrir o arquivo\n";
      exit(1);
  }
      fread(&obraCad, sizeof(obras), 1, livroArq);

      cout<<"\n Titulo da obra:...."<<obraCad.titulo<<endl;
      cout<<"\n Ano publicado:..."<<obraCad.ano<<endl;
      cout<<"\n Codigo do livro:...."<<obraCad.codigo<<endl;
      fclose(livroArq);
  }

  void procurar_obra() {
      system("cls");
      livroArq = fopen("livros.bin", "rb");
      if (livroArq == NULL) {
          cout << "\nErro ao abrir o arquivo\n";
          exit(1);
      }
      int codigoBusca;
      int achou = 0;

      cout << "\nInforme o codigo do livro a ser procurado: ";
      cin >> codigoBusca;

      while (fread(&obraCad, sizeof(obras), 1, livroArq) == 1) {
          if (codigoBusca == obraCad.codigo) {
              cout << "\nObra encontrada!";
              cout << "\nTitulo: " << obraCad.titulo;
              cout << "\nCodigo: " << obraCad.codigo;
              cout << "\nAno: " << obraCad.ano;
              achou = 1;
              break;
          }
      }

      if (achou == 0){
          cout << "\n Obra não encontrada.";}

      fclose(livroArq);
      system("pause");
  }

  void menu() {
      int op;
      do {
          system("cls");
          cout << "\n ----------------------------------------\n";
          cout<<"\n***LIVRARIA DA CI,COMO POSSO AJUDAR?***\n";
          cout << "\n ----------------------------------------\n";
          cout << "\n*** MENU PRINCIPAL ***\n";
          cout << "\n 1 - Cadastrar obra literaria";
          cout << "\n 2 - Mostrar obras cadastradas";
          cout<<  "\n 3 - Procurar obra";
          cout << "\n 0 - Sair";
          cout << "\nEscolha: ";
          cin >> op;

          switch (op) {
              case 1:
                  cadastro_livro();
                  break;
              case 2:
                  mostrar_obras();
                  break;
              case 3:
                  procurar_obra();
                  break;
              case 0:
                  cout << "Saindo...\n";
                  break;
              default:
                  cout << "Opção inválida!\n";
                  system("pause");
          }
      } while (op != 0);
  }


  int main() {
      menu();
      return 0;
  }
