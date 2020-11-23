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
  struct date check_in;
  struct date check_out;
} EVENT;

/**
 * @brief tipo de dados que define as agendas
 * @details calendário individual por plataforma
 */
typedef struct agenda {
  struct event event;
} AGENDA;

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
 * @brief Tipo de dados que guarda as moradas dos estúdios
 * @details contém a rua, o piso do edificio,
 * o código postal, a latitude e a longitude
 */
typedef struct address {
  char* street;
  int floor;
  char* zip;
  double latitude;
  double longitude;
} ADDRESS;

/**
 * @brief Tipo de dados que define os edificios
 * @details contém o nome do edificio, e aponta para o proximo edificio
 */
typedef struct building {
  char* name;
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
  char* name;
  struct address address;
} STUDIO;

#endif
