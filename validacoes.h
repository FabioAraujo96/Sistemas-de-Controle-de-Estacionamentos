
int validacpf(char * );//função que valida cpf
int cpfJaExiste(char*);// função que verifica se o cpf ja existe
int validaloginfunusuario(char*);// função que verificaria se o funcionário estava digitando o usuasrio e senha correto
int validaEmail(char*);//função para validar email
int validaNome(char*);// função que valida nome
#define RE_NAME "[A-Z a-z A-ZàáâäãåąčćęèéêëėįìíîïłńòóôöõøùúûüųūÿýżźñçčšžÀÁÂÄÃÅĄĆČĖĘÈÉÊËÌÍÎÏĮŁŃÒÓÔÖÕØÙÚÛÜŲŪŸÝŻŹÑßÇŒÆČŠŽ∂ð'*]$"