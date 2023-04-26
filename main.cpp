#include <iostream>
#include <time.h>
using namespace std;

struct horario{
    int hora;
    int minuto;
    int segundo;
};

struct data{
    int dia;
    int mes;
    int ano;
};

struct pessoa{
    string nome;
    data nascimento;
    int idade;

};

struct obra{
    string nome;
    data lancamento;
    pessoa autor;
    int paginas;
    string tipo;
};

struct cadastro{
    obra sessao [10];
    data cadastro;
};

struct prateleira{
    cadastro a [200];
};

void hoje(data a){
     time_t mytime;
    mytime = time(NULL);
    struct tm tm = *localtime(&mytime);
    printf("Data: %d/%d/%d\n", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);
    a.ano=tm.tm_year+1900;
    a.mes=tm.tm_mon+1;
    a.dia=tm.tm_mday;
}

void lerPessoa(pessoa& a){
    data aux;
    hoje(aux);
    cout<<endl;
    cout<<"Insira o nome: ";
    getline(cin,a.nome);
    cout<<endl;
    do{
    cout<<"Insira seu dia de nascimento: ";
    cin>>a.nascimento.dia;
    cout<<endl;
    }while(a.nascimento.dia<0||a.nascimento.dia>31||isalnum(a.nascimento.dia)==true||isalpha(a.nascimento.dia)==true);
    do{
    cout<<"Insira seu mes de nascimento: ";
    cin>>a.nascimento.mes;
    cout<<endl;
    }while(a.nascimento.mes<0||a.nascimento.mes>12||isalnum(a.nascimento.mes)==true||isalpha(a.nascimento.mes)==true);
    do{
    cout<<"Insira seu ano de nascimento: ";
    cin>>a.nascimento.ano;
    cout<<endl;
    }while(a.nascimento.ano<0||a.nascimento.ano>2022||isalnum(a.nascimento.ano)==true||isalpha(a.nascimento.ano)==true);
    aux.mes=4;
    aux.ano=2023;
    aux.dia=25;
    if(a.nascimento.mes>=aux.mes){
        if(a.nascimento.dia>=aux.dia){
            a.idade = aux.ano-a.nascimento.ano;
        }
        else{
        a.idade = (aux.ano-a.nascimento.ano)-1;
        }
    }
    else{
    a.idade = aux.ano-a.nascimento.ano;
    }
}

void lerObra(obra& a){
    cin.ignore();
    cout<<"Insira o tipo da obra: ";
    getline(cin,a.tipo);
    cout<<endl;
    cout<<"Insira o nome da obra: ";
    getline(cin,a.nome);
    cout<<endl;
    do{
    cout<<"Insira a quantidade de páginas: ";
    cin>>a.paginas;
    cout<<endl;
    }while(a.paginas<1||isalnum(a.paginas)==true||isalpha(a.paginas)==true);
    cin.ignore();
    cout<<"Insira o nome do autor: ";
    getline(cin,a.autor.nome);
    cout<<endl;
    do{
    cout<<"Insira o dia de lançamento do livro: ";
    cin>>a.lancamento.dia;
    cout<<endl;
    }while(a.lancamento.dia<1||a.lancamento.dia>31||isalnum(a.lancamento.dia)==true||isalpha(a.lancamento.dia)==true);
    do{
    cout<<"Insira o mês de lançamento do livro: ";
    cin>>a.lancamento.mes;
    cout<<endl;
    }while(a.lancamento.mes<1||a.lancamento.mes>12||isalnum(a.lancamento.mes)==true||isalpha(a.lancamento.mes)==true);
    do{
    cout<<"Insira o ano de lançamento do livro: ";
    cin>>a.lancamento.ano;
    cout<<endl;
    }while(a.lancamento.ano<1||a.lancamento.ano>2022||isalnum(a.lancamento.ano)==true||isalpha(a.lancamento.ano)==true);

}

void escreverPessoa(pessoa a){
    cout<<endl;
    cout<<"Nome: "<<a.nome<<endl;
    printf("Data de nascimento: %d/%d/%d\n",a.nascimento.dia,a.nascimento.mes,a.nascimento.ano);
    cout<<"Idade: "<<a.idade;
}

void escreverObra(obra a){
    cout<<"Tipo: "<<a.tipo<<endl;
    cout<<"Nome da obra: "<<a.nome<<endl;
    cout<<"Nome do autor: "<<a.autor.nome<<endl;
    cout<<"Número de páginas: "<<a.paginas<<endl;
    printf("Dada de lançamento: %d/%d/%d\n",a.lancamento.dia,a.lancamento.mes,a.lancamento.ano);
}

data devolucao(data a){

}

void cadastrar(prateleira& a,int& tam){
    bool sair=false;
    int aux;
    for(int i=0;i<tam;i++){
     do{
        cout<<endl;
        cout<<"     Obra ["<<i+1<<"]     "<<endl;
        cout<<endl;
        lerObra(a.a[i].sessao[i]);
        do{
        cout<<"[1] - Continuar cadastro"<<endl;
        cout<<"[2] - Sair"<<endl;
        cin>>aux;
        //if(aux==2){
           // sair=true;
       // }
        }while(aux!=1&&aux!=2);
        if(aux==2){
            sair=true;
        }
        }while(sair==false);
    }
}

void escreverCadastro(prateleira& a,int& tam){
    for(int i=0;i<tam;i++){
        cout<<endl;
        cout<<"     Obra ["<<i+1<<"]     "<<endl;
        cout<<endl;
        escreverObra(a.a[i].sessao[i]);
    }
}



int main()
{
    data atualizada;
    prateleira a;
    int tam;
    pessoa cliente;
    obra b;
    cout<<"Quantos livros você deseja cadastrar?"<<endl;
    cin>>tam;

    cadastrar(a,tam);
    escreverCadastro(a,tam);


    return 0;
}
