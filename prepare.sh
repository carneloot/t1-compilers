NAME='regalloc'

echo "Criando arquivo \"$NAME.zip\" para enviar."

# Remove o .zip antigo
rm -f $NAME.zip

# Cria pasta
mkdir -p $NAME

# Copia os arquivos necessarios
cp -r src/* $NAME/
cp -r include/* $NAME/
cp Makefile $NAME/

# Muda os parametros do Makefile
sed -i -e 's/= src/= ./g' $NAME/Makefile
sed -i -e 's/= build/= ./g' $NAME/Makefile
sed -i -e 's/= bin/= ./g' $NAME/Makefile
sed -i -e 's/= include/= ./g' $NAME/Makefile
sed -i -e 's/DEBUG = 1/DEBUG = 0/g' $NAME/Makefile

# Compacta a pasta
zip -qrj $NAME $NAME/*

# Remove a pasta
rm -rf $NAME/

echo "Processo concluido!"
