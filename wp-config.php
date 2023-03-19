<?php
/** 
 * Configuración básica de WordPress.
 *
 * Este archivo contiene las siguientes configuraciones: ajustes de MySQL, prefijo de tablas,
 * claves secretas, idioma de WordPress y ABSPATH. Para obtener más información,
 * visita la página del Codex{@link http://codex.wordpress.org/Editing_wp-config.php Editing
 * wp-config.php} . Los ajustes de MySQL te los proporcionará tu proveedor de alojamiento web.
 *
 * This file is used by the wp-config.php creation script during the
 * installation. You don't have to use the web site, you can just copy this file
 * to "wp-config.php" and fill in the values.
 *
 * @package WordPress
 */

// ** Ajustes de MySQL. Solicita estos datos a tu proveedor de alojamiento web. ** //
/** El nombre de tu base de datos de WordPress */
define('DB_NAME', 'gobernanza_aire');

/** Tu nombre de usuario de MySQL */
define('DB_USER', 'root');

/** Tu contraseña de MySQL */
define('DB_PASSWORD', '*WeirdNovic29!');

/** Host de MySQL (es muy probable que no necesites cambiarlo) */
define('DB_HOST', 'localhost');

/** Codificación de caracteres para la base de datos. */
define('DB_CHARSET', 'utf8mb4');

/** Cotejamiento de la base de datos. No lo modifiques si tienes dudas. */
define('DB_COLLATE', '');

/**#@+
 * Claves únicas de autentificación.
 *
 * Define cada clave secreta con una frase aleatoria distinta.
 * Puedes generarlas usando el {@link https://api.wordpress.org/secret-key/1.1/salt/ servicio de claves secretas de WordPress}
 * Puedes cambiar las claves en cualquier momento para invalidar todas las cookies existentes. Esto forzará a todos los usuarios a volver a hacer login.
 *
 * @since 2.6.0
 */
define('AUTH_KEY', 'd!&u(AO=C*c0WT&FQwcn/)>:ng5;hxWO^fk9& B%G{SB,FLQ,G:g3UyQ759-@&vT');
define('SECURE_AUTH_KEY', 'H{u-_j!KqSH2 HAM@q+B6g[2XW!1E!%zs~dN/D*l9HN&})e`Xf:?SpeGB_YBOEr+');
define('LOGGED_IN_KEY', 'FEv%d-%2Uhgf/TH<]mpTz},_2(f0i<#4zoR(6@8(Yz;t4*)BpU0C<U 5-dm,mh}l');
define('NONCE_KEY', 'M<<NZ^=*`_}h.H.YqcqE1s$W?Ph{k/i?[S#3F1dwm$31oSkB1icLARCsdSEDb)|^');
define('AUTH_SALT', 'ln_StdA+hN8m?zT;M0r{*y7 *tt76{^-MT((nkz3(0n L#(;[l{i49fTuPslfAd=');
define('SECURE_AUTH_SALT', 'aC({)/G2$T+E~XD1qIODlfM*n&XPz]zzzKTpQ^8pD7wf!*:$~EnFuQ-osg,$Aq[5');
define('LOGGED_IN_SALT', 'A$DJ9TD<F} PF<C;-AA#FRiH5Z*{nj_ts[X55f,Tq&TY]ES.StKOR5pqCkk3(vM>');
define('NONCE_SALT', ',:?tW>fl@J}s;LcDlO2SrQx=?%kn9@#kUtJ|,Lv2p<cB$htHrHs|=PZDtj:sM9Fx');

/**#@-*/

/**
 * Prefijo de la base de datos de WordPress.
 *
 * Cambia el prefijo si deseas instalar multiples blogs en una sola base de datos.
 * Emplea solo números, letras y guión bajo.
 */
$table_prefix  = 'pw_';


/**
 * Para desarrolladores: modo debug de WordPress.
 *
 * Cambia esto a true para activar la muestra de avisos durante el desarrollo.
 * Se recomienda encarecidamente a los desarrolladores de temas y plugins que usen WP_DEBUG
 * en sus entornos de desarrollo.
 */
define('WP_DEBUG', false);

/* ¡Eso es todo, deja de editar! Feliz blogging */

/** WordPress absolute path to the Wordpress directory. */
if ( !defined('ABSPATH') )
	define('ABSPATH', dirname(__FILE__) . '/');

/** Sets up WordPress vars and included files. */
require_once(ABSPATH . 'wp-settings.php');

