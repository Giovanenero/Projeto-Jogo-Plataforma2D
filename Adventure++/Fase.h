#pragma once

#include "Ente.h"

#include "GerenciadorGrafico.h"
#include "GerenciadorEvento.h"
#include "GerenciadorColisao.h"
#include "Oriana.h"
#include "BateGoblin.h"
#include "AtiraGoblin.h"
#include "BateEsqueleto.h"
#include "AtiraEsqueleto.h"
#include "Animagus.h"
#include "Noturno.h"
#include "Plataforma.h"
#include "Ponte.h"
#include "Andaime.h"
#include "Espinhos.h"
#include "Pedra.h"
#include "Caixa.h"
#include "Fundo.h"

#include <time.h>

namespace Fase {
    class Fase: public Ente
    {
    protected:
        Gerenciador::GerenciadorGrafico* pGrafico;
        Gerenciador::GerenciadorEvento* pEvento;
        Entidade::Personagem::Jogador::Oriana *pOriana;
        Entidade::Personagem::Jogador::Hideo* pHideo;
        Lista::ListaEntidade *ListaEntidadeEstatica;
        Lista::ListaEntidade *ListaEntidadeMovimento;
        Gerenciador::GerenciadorColisao* pColisao;
        Fundo* fundo;
        bool iniciou;
        bool doisJogadores;
        float tempoTroca;
    public:
        Fase();
        virtual ~Fase();
        virtual void init() = 0;
        virtual void executar() = 0;
        virtual void atualizar(const float tempo) = 0;

        void setDoisJogadores(bool dJ);
        void trocarJogadores();
        Entidade::Entidade* instaciaEntidade(Matematica::CoordenadaF pos, short tipo);
    };
}