# Point-Store
Aplicacion que proporcione el control administrativo de un punto de venta( Altas, Bajas y cambios ) que garantiza seguridad en los datos.

# Intrucciones para la compilacion

-   Si las cadenas a mostrar al usuario no son eliminadas, modificadas o agregadas, simplemente ejecutar:

    $ make

-   Si las cadenas a mostrar al usuario fueron eliminadas, modificadas o agregadas, se deben ver reflejadas
    en el template pot, para esto ejecutamos generamos el template y actualizamos el archivo po, para su
    posterior traduccion. Lo hacemos de la siguiente forma:

    $ make actualizar-archivos-po

-   Y despues, de haber actualizado los archivos de lenguaje, compilamos los fuentes:

    $ make