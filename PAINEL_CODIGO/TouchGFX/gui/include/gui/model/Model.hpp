#ifndef MODEL_HPP
#define MODEL_HPP

class ModelListener;

class Model
{
public:
    Model();

    void bind(ModelListener* listener)
    {
        modelListener = listener;
    }

    void tick();

    // essas são as funçoes que vao receber os dados do can e mandar pro presenter
    // tela de testes e modo de prova
    float funcorrenteAcc(){return correnteAcc; }
	float funSOC(){return SOC; }
	float funpotencia(){return potencia; }
	float funtempAcc(){return tempAcc; }
	float funtempMotor(){return tempMotor; }
	float funtempInv(){return tempInv; }
	float funtensaoInv(){return tensaoInv; }
	float funtensaoHV(){return tensaoHV; }
	float funtensaoMC(){return tensaoMC; }
	int funrpm(){return rpm; }
	int funvelocidade(){return velocidade; }
	float funfreio(){return freio; }
	float funacelerador(){return acelerador; }
protected:
    ModelListener* modelListener;
    //variaveis que vamos usar
    // obs se a informação for de tipo diferente mudar o tipo da variavel tanto aqui quanto na função correspondente
    // eu so deduzir o tipo pra deixar ja pronta as variaveis

    float correnteAcc;
	float SOC;
	float potencia;
	float tempAcc;
	float tempMotor;
	float tempInv;
	float tensaoInv;
	float tensaoHV;
	float tensaoMC;
	int rpm;
	int velocidade;
	float freio;
	float acelerador;
};

#endif // MODEL_HPP
