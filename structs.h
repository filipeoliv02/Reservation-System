#ifndef AED1_LP1_STRUCTS_H
#define AED1_LP1_STRUCTS_H

/**
 * @brief tipo de dados para datas
 * @details estrutura para garantir a boa formatação das datas
 */
typedef struct date {
  int day;
  int month;
  int year;
  int hour;
  int minutes;
} DATE;

/**
 * @brief Tipo de Dados para registo de envetos
 * @details Estrutura de dados para registo/leitura de eventos, os eventos
 * têm relação directar com ->Plataform.
 * Cada novo registo de evento irá ser pedido os seguintes atributos:
 * check_in (estrutura data)
 * check_out (estrutura data)
 * plataform
 */
typedef struct event {
  int id;
  char* type;
  struct date check_in;
  struct date check_out;
  int guest;
  int studio;
  char* plataform;
} EVENT;

/**
 * @brief tipo de dados que define as agendas
 * @details calendário individual por plataforma
 */
typedef struct agenda {
  struct event event;
} AGENDA;

typedef struct policies{
  char* policies;
  char* platform;
  char* rules[];
}POLICIES;
/**
 * @brief tipo de dados para as diversas plataformas
 * @details name é o nome da plataforma. website é a hiperligação
 * da página online da plataforma e contem a sua agenda
 */
typedef struct platform {
  char* name;
  char* website;
  struct agenda agenda;
} PLATFORM;


/**
 * @brief Tipo de dados que define os edificios
 * @details contém o nome do edificio, e aponta para o proximo edificio
 */
typedef struct building {
  int id;
  char* name;
  double latitude;
  double longitude;
  char* address;
  double priceperday;
  struct building* next;
  struct studio* studios;
} BUILDING;

/**
 * @brief tipo de dados que define os estúdios
 * @details contém a tipologia do estúdio (T2, T3...)
 * aponta para o edifício a que pertence
 * e contém a morada
 */
typedef struct studio {
  // char name alterar depois para tipo de estudio
  int id;
  int number;
  int building;
  char* config;
  int area;
} STUDIO;

/**
 * @brief tipo de dados para definir os hóspedes
 * @details contem o nome, a nacionalidade e o histórico de estadias do hóspede
 *
 */
typedef struct guest {
  char* name;
  char* country;
  STUDIO* history;
} GUEST;


#endif
