#include "Caixa.h"

#define TAMANHO_CAIXA_X 50.0f
#define TAMANHO_CAIXA_Y 50.0f

namespace Entidade {
    namespace Obstaculo {
        Caixa::Caixa(Matematica::CoordenadaF posInicio):
            Obstaculo(posInicio, Matematica::CoordenadaF(TAMANHO_CAIXA_X, TAMANHO_CAIXA_Y), Ids::Ids::caixa),
            empurrar(true)
        {
            this->inicializacao();
        }
        Caixa::~Caixa() {

        }
        void Caixa::inicializacao() {
            pAnimacaoEstatica->novaAnimacao("textura/Obstaculos/caixa.png", Ids::Ids::caixa, posicao, tamanho, Matematica::CoordenadaF(1.6f, 2.2f));
        }
        void Caixa::atualizar() {
            pAnimacaoEstatica->atualizar(Ids::Ids::caixa, posicao);
            pAnimacaoEstatica->renderizar();
        }
        void Caixa::setEmpurrar(bool empurrar) { this->empurrar = empurrar; }
        const bool Caixa::getEmpurrar() const { return empurrar; }
    }
}