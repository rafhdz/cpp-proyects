#include <iostream>
#include <string>
using namespace std;

class Cliente {
private:
    string nombre;
    string email;
    long telefono;

public:
    void setNombre() {
        cout << "Ingresa tu nombre: ";
        cin >> nombre;
    }

    void setEmail() {
        cout << "Ingresa tu email: ";
        cin >> email;
    }

    void setTelefono() {
        cout << "Ingresa tu número telefónico: ";
        cin >> telefono;
    }

    string getNombre() {
        return nombre;
    }

    string getEmail() {
        return email;
    }

    long getTelefono() {
        return telefono;
    }
};

class Productos {
protected:
    int id;
    int seleccion;
    int valorProducto1;
    int valorProducto2;

public:
    void setSeleccion() {
        cout << "Ingresa el # para el producto que desees: \n[1] Producto1 ($500)\n[2] Producto2 ($200)" << endl;
        cin >> seleccion;
    }

    int getSeleccion() {
        return seleccion;
    }
};

class Pedido : public Productos {
private:
    string idPedido;
    string fechaPedido;
    int total;

public:
    void setIdPedido(string i) {
        idPedido = i;
    }

    void setFechaPedido(string f) {
        fechaPedido = f;
    }

    void setTotal() {
        if (seleccion == 1) {
            total = valorProducto1;
        }
        else if (seleccion == 2) {
            total = valorProducto2;
        }
    }

    void setValorProducto1(int p1) {
        valorProducto1 = p1;
    }

    void setValorProducto2(int p2) {
        valorProducto2 = p2;
    }

    int getValorProducto1() {
        return valorProducto1;
    }

    int getValorProducto2() {
        return valorProducto2;
    }

    string getIdPedido() {
        return idPedido;
    }

    string getFechaPedido() {
        return fechaPedido;
    }

    int getTotal() {
        return total;
    }
};

class Envio : public Pedido, public Cliente {
private:
    string idEnvio;
    int envio1;
    int envio2;
    string direccion;
    int costoEnvio;
    int company;
    string logistica;

public:
    void setidEnvio(string ie) {
        idEnvio = ie;
    }

    void setEnvio1(int e1) {
        envio1 = e1;
    }

    void setEnvio2(int e2) {
        envio2 = e2;
    }

    void setDireccion(string d) {
        direccion = d;
    }

    void setCostoEnvio() {
        if (company == 1) {
            costoEnvio = envio1;
        }
        else if (company == 2) {
            costoEnvio = envio2;
        }
    }

    void setLogistica() {
        if (company == 1) {
            logistica = "FedEx 1-2 días";
        }
        else if (company == 2) {
            logistica = "DHL 3-5 días";
        }
    }

    void setCompany() {
        cout << "\nIngresa el # para seleccionar la compañía de logística que te entregará el producto:\n[1] FedEx 1-2 días ($250)\n[2] DHL 3-5 días ($175)\n";
        cin >> company;
    }

    string getIdEnvio() {
        return idEnvio;
    }

    string getDireccion() {
        return direccion;
    }

    int getCostoEnvio() {
        return costoEnvio;
    }

    int getEnvio1() {
        return envio1;
    }

    int getEnvio2() {
        return envio2;
    }

    string getLogistica() {
        return logistica;
    }
};

class Pago : public Envio, public Pedido {
private:
    string tipoPago;
    int seleccionTipo;

public:
    void setSeleccionTipo() {
        cout << "Ingresa el # para seleccionar el método de pago que quieras realizar:\n[1] Tarjeta digital\n[2] Paypal\n";
        cin >> seleccionTipo;
    }

    void setTipoPago() {
        if (seleccionTipo == 1) {
            tipoPago = "Tarjeta digital";
        }
        else if (seleccionTipo == 2) {
            tipoPago = "PayPal";
        }
    }

    string getTipoPago() {
        return tipoPago;
    }

    int getSeleccionTipo() {
        return seleccionTipo;
    }
};

class TarjetaDigital : public Pago {
private:
    string nombreTD;
    long datosBancarios[3];

public:
    void setNombreTD() {
        cout << "Ingresa el nombre del titular de tarjeta: ";
        cin >> nombreTD;
    }

    void setDatosBancarios() {
        cout << "Ingresa el número de tarjeta: ";
        cin >> datosBancarios[0];
        cout << "Ingresa el CVV: ";
        cin >> datosBancarios[1];
        cout << "Ingresa el año de vencimiento: ";
        cin >> datosBancarios[2];
    }

    string getNombreTD() {
        return nombreTD;
    }

    long getNumeroCuenta() {
        return datosBancarios[0];
    }

    long getCVV() {
        return datosBancarios[1];
    }

    long getAno() {
        return datosBancarios[2];
    }
};

class PayPal : public Pago {
private:
    string emailPP;
    string password;

public:
    void setEmailPP() {
        cout << "Ingresa tu email: ";
        cin >> emailPP;
    }

    void setPassword() {
        cout << "Ingresa tu contraseña: ";
        cin >> password;
    }

    string getEmailPP() {
        return emailPP;
    }

    string getPassword() {
        return password;
    }
};

int main() {
    Cliente infoCliente;
    cout << "--------------- CREACIÓN DE CUENTA ---------------" << endl;
    infoCliente.setNombre();
    infoCliente.setEmail();
    infoCliente.setTelefono();

    Pedido infoPedido;
    infoPedido.setIdPedido("#4GPA54K3");
    infoPedido.setValorProducto1(500);
    infoPedido.setValorProducto2(200);
    infoPedido.setFechaPedido("Domingo 27 Noviembre 2022");
    infoPedido.setSeleccion();
    infoPedido.setTotal();
    cout << "Total: " << infoPedido.getTotal() << endl;

    Envio infoEnvio;
    cout << "--------------- ENVÍO ---------------" << endl;
    infoEnvio.setidEnvio("#32K52FD");
    infoEnvio.setEnvio1(250);
    infoEnvio.setEnvio2(175);
    infoEnvio.setDireccion("Tecnólogico de Monterrey");
    infoEnvio.setCompany();
    infoEnvio.setCostoEnvio();
    infoEnvio.setLogistica();

    cout << "--------------- INFORMACIÓN DE ENVÍO ---------------" << endl;
    cout << "ID del envío: " << infoEnvio.getIdEnvio() << endl;
    cout << "Fecha del pedido: " << infoPedido.getFechaPedido() << endl;
    cout << "Logística: " << infoEnvio.getLogistica() << endl;
    cout << "Nombre: " << infoCliente.getNombre() << endl;
    cout << "Email: " << infoCliente.getEmail() << endl;
    cout << "Teléfono: " << infoCliente.getTelefono() << endl;
    cout << "Dirección: " << infoEnvio.getDireccion() << endl;
    cout << "Costo de envío: $" << infoEnvio.getCostoEnvio() << endl;

    Pago infoPago;
    cout << "--------------- TIPO DE PAGO ---------------" << endl;
    infoPago.setSeleccionTipo();
    infoPago.setTipoPago();

    cout << "--------------- INFORMACIÓN DEL PAGO ---------------" << endl;
    cout << "ID del pago: " << infoPedido.getIdPedido() << endl;
    cout << "Total a pagar: $" << infoPedido.getTotal() + infoEnvio.getCostoEnvio() << endl;
    cout << "Método seleccionado: " << infoPago.getTipoPago() << endl;

    TarjetaDigital infoTD;
    PayPal infoPP;

    if (infoPago.getSeleccionTipo() == 1) {
        cout << "--------------- TARJETA DIGITAL ---------------" << endl;
        infoTD.setNombreTD();
        infoTD.setDatosBancarios();

        cout << "--------------- DATOS BANCARIOS ---------------" << endl;
        cout << "Nombre del titular de tarjeta: " << infoTD.getNombreTD() << endl;
        cout << "Número de cuenta: " << infoTD.getNumeroCuenta() << endl;
        cout << "CVV: " << infoTD.getCVV() << endl;
        cout << "Año de vencimiento: " << infoTD.getAno() << endl;
        cout << "Completando el pago..." << endl;
        cout << "Pago completado!" << endl;
    }
    else if (infoPago.getSeleccionTipo() == 2) {
        cout << "--------------- PAYPAL ---------------" << endl;
        infoPP.setEmailPP();
        infoPP.setPassword();
        cout << "Completando el pago..." << endl;
        cout << "Pago completado!" << endl;
    }

    string cont_datos;
    cout << "Inserte 'Si' para continuar en el sistema" << endl;
    cout << "Inserte 'No' para terminar el sistema" << endl;
    cin >> cont_datos;

    if (cont_datos == "Si") {
        cout << "El sistema permite agregar productos adicionales" << endl;
        cout << "para vender en el sistema" << endl;
        cout << "Inserte el número de productos a agregar" << endl;
        int num_articulos;
        cin >> num_articulos;
        string articulos_extra_n[num_articulos];
        int articulos_extra_p[num_articulos];
        string nom_art;
        int precio_art;

        for (int i = 0; i < num_articulos; i++) {
            cout << "Ponga el nombre para su artículo" << endl;
            cin >> nom_art;
            articulos_extra_n[i] = nom_art;
            cout << "Ponga el precio para su artículo" << endl;
            cout << "El precio tiene que ser mayor que $300" << endl;
            cin >> precio_art;

            try {
                if (precio_art >= 300) {
                    cout << "Precio cumple con los requisitos" << endl;
                    articulos_extra_p[i] = precio_art;
                }
                else {
                    throw (precio_art);
                }
            }
            catch (int p) {
                cout << "No se permite ese precio" << endl;
                cout << "Su precio fue " << p << endl;
            }
        }
        cout << "Proceso finalizado!" << endl;
    }
    else if (cont_datos == "No") {
        cout << "Muchas gracias por usar el sistema" << endl;
        cout << "Sistema finalizado" << endl;
    }

    return 0;
}
