SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0;
SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0;
SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='TRADITIONAL,ALLOW_INVALID_DATES';

CREATE SCHEMA IF NOT EXISTS `mydb` DEFAULT CHARACTER SET utf8 COLLATE utf8_general_ci ;
USE `mydb` ;

-- -----------------------------------------------------
-- Table `mydb`.`Usuario`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `mydb`.`Usuario` (
  `idUsuario` INT NOT NULL,
  `nombre` VARCHAR(45) NULL,
  `Nivel` VARCHAR(45) NULL,
  `password` VARCHAR(45) NULL,
  PRIMARY KEY (`idUsuario`))
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `mydb`.`productos`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `mydb`.`productos` (
  `idproductos` INT NOT NULL,
  `nombre` VARCHAR(45) NULL,
  `descripcion` VARCHAR(45) NULL,
  `precio` VARCHAR(45) NULL,
  PRIMARY KEY (`idproductos`))
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `mydb`.`venta`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `mydb`.`venta` (
  `idventa` INT NOT NULL,
  `Usuario_idUsuario` INT NOT NULL,
  `fecha` VARCHAR(45) NOT NULL,
  PRIMARY KEY (`idventa`, `Usuario_idUsuario`),
  INDEX `fk_venta_Usuario1_idx` (`Usuario_idUsuario` ASC),
  CONSTRAINT `fk_venta_Usuario1`
    FOREIGN KEY (`Usuario_idUsuario`)
    REFERENCES `mydb`.`Usuario` (`idUsuario`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `mydb`.`Pedido`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `mydb`.`Pedido` (
  `idPedido` INT NOT NULL,
  `Fecha` DATE NULL,
  `Hora` VARCHAR(45) NULL,
  `Usuario_idUsuario` INT NOT NULL,
  PRIMARY KEY (`idPedido`, `Usuario_idUsuario`),
  INDEX `fk_Pedido_Usuario1_idx` (`Usuario_idUsuario` ASC),
  CONSTRAINT `fk_Pedido_Usuario1`
    FOREIGN KEY (`Usuario_idUsuario`)
    REFERENCES `mydb`.`Usuario` (`idUsuario`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `mydb`.`Inventario`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `mydb`.`Inventario` (
  `idInventario` INT NOT NULL,
  `productos_idproductos` INT NOT NULL,
  `cantidadExistente` VARCHAR(45) NULL,
  PRIMARY KEY (`idInventario`, `productos_idproductos`),
  INDEX `fk_Inventario_productos1_idx` (`productos_idproductos` ASC),
  CONSTRAINT `fk_Inventario_productos1`
    FOREIGN KEY (`productos_idproductos`)
    REFERENCES `mydb`.`productos` (`idproductos`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `mydb`.`venta_has_productos`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `mydb`.`venta_has_productos` (
  `venta_idventa` INT NOT NULL,
  `venta_Usuario_idUsuario` INT NOT NULL,
  `productos_idproductos` INT NOT NULL,
  PRIMARY KEY (`venta_idventa`, `venta_Usuario_idUsuario`, `productos_idproductos`),
  INDEX `fk_venta_has_productos_productos1_idx` (`productos_idproductos` ASC),
  INDEX `fk_venta_has_productos_venta1_idx` (`venta_idventa` ASC, `venta_Usuario_idUsuario` ASC),
  CONSTRAINT `fk_venta_has_productos_venta1`
    FOREIGN KEY (`venta_idventa` , `venta_Usuario_idUsuario`)
    REFERENCES `mydb`.`venta` (`idventa` , `Usuario_idUsuario`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION,
  CONSTRAINT `fk_venta_has_productos_productos1`
    FOREIGN KEY (`productos_idproductos`)
    REFERENCES `mydb`.`productos` (`idproductos`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `mydb`.`Pedido_has_productos`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `mydb`.`Pedido_has_productos` (
  `Pedido_idPedido` INT NOT NULL,
  `Pedido_Usuario_idUsuario` INT NOT NULL,
  `productos_idproductos` INT NOT NULL,
  PRIMARY KEY (`Pedido_idPedido`, `Pedido_Usuario_idUsuario`, `productos_idproductos`),
  INDEX `fk_Pedido_has_productos_productos1_idx` (`productos_idproductos` ASC),
  INDEX `fk_Pedido_has_productos_Pedido1_idx` (`Pedido_idPedido` ASC, `Pedido_Usuario_idUsuario` ASC),
  CONSTRAINT `fk_Pedido_has_productos_Pedido1`
    FOREIGN KEY (`Pedido_idPedido` , `Pedido_Usuario_idUsuario`)
    REFERENCES `mydb`.`Pedido` (`idPedido` , `Usuario_idUsuario`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION,
  CONSTRAINT `fk_Pedido_has_productos_productos1`
    FOREIGN KEY (`productos_idproductos`)
    REFERENCES `mydb`.`productos` (`idproductos`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


SET SQL_MODE=@OLD_SQL_MODE;
SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS;
SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS;
