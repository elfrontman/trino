<?php

if(!function_exists('optimize_mikado_register_top_header_areas')) {
    /**
     * Registers widget areas for top header bar when it is enabled
     */
    function optimize_mikado_register_top_header_areas() {
        $top_bar_layout  = optimize_mikado_options()->getOptionValue('top_bar_layout');

        register_sidebar(array(
            'name'          => esc_html__('Top Bar Left', 'optimize'),
            'id'            => 'mkdf-top-bar-left',
            'before_widget' => '<div id="%1$s" class="widget %2$s mkdf-top-bar-widget"><div class="mkdf-top-bar-widget-inner">',
            'after_widget'  => '</div></div>'
        ));

        //register this widget area only if top bar layout is three columns
        if($top_bar_layout === 'three-columns') {
            register_sidebar(array(
                'name'          => esc_html__('Top Bar Center', 'optimize'),
                'id'            => 'mkdf-top-bar-center',
                'before_widget' => '<div id="%1$s" class="widget %2$s mkdf-top-bar-widget"><div class="mkdf-top-bar-widget-inner">',
                'after_widget'  => '</div></div>'
            ));
        }

        register_sidebar(array(
            'name'          => esc_html__('Top Bar Right', 'optimize'),
            'id'            => 'mkdf-top-bar-right',
            'before_widget' => '<div id="%1$s" class="widget %2$s mkdf-top-bar-widget"><div class="mkdf-top-bar-widget-inner">',
            'after_widget'  => '</div></div>'
        ));
    }

    add_action('widgets_init', 'optimize_mikado_register_top_header_areas');
}

if(!function_exists('optimize_mikado_header_standard_widget_areas')) {
    /**
     * Registers widget areas for standard header type
     */
    function optimize_mikado_header_standard_widget_areas() {
        if(optimize_mikado_options()->getOptionValue('header_type') == 'header-standard') {
            register_sidebar(array(
                'name'          => esc_html__('Right From Main Menu', 'optimize'),
                'id'            => 'mkdf-right-from-main-menu',
                'before_widget' => '<div id="%1$s" class="widget %2$s mkdf-right-from-main-menu-widget"><div class="mkdf-right-from-main-menu-widget-inner">',
                'after_widget'  => '</div></div>',
                'description'   => esc_html__('Widgets added here will appear on the right hand side from the main menu', 'optimize')
            ));
        }
    }

    add_action('widgets_init', 'optimize_mikado_header_standard_widget_areas');
}

if(!function_exists('optimize_mikado_header_vertical_widget_areas')) {
    /**
     * Registers widget areas for vertical header
     */
    function optimize_mikado_header_vertical_widget_areas() {
        if(optimize_mikado_options()->getOptionValue('header_type') == 'header-vertical') {
            register_sidebar(array(
                'name'          => esc_html__('Vertical Area', 'optimize'),
                'id'            => 'mkdf-vertical-area',
                'before_widget' => '<div id="%1$s" class="widget %2$s mkdf-vertical-area-widget">',
                'after_widget'  => '</div>',
                'description'   => esc_html__('Widgets added here will appear on the bottom of vertical menu', 'optimize')
            ));
        }
    }

    add_action('widgets_init', 'optimize_mikado_header_vertical_widget_areas');
}

if(!function_exists('optimize_mikado_register_mobile_header_areas')) {
    /**
     * Registers widget areas for mobile header
     */
    function optimize_mikado_register_mobile_header_areas() {
        if(optimize_mikado_is_responsive_on()) {
            register_sidebar(array(
                'name'          => esc_html__('Right From Mobile Logo', 'optimize'),
                'id'            => 'mkdf-right-from-mobile-logo',
                'before_widget' => '<div id="%1$s" class="widget %2$s mkdf-right-from-mobile-logo">',
                'after_widget'  => '</div>',
                'description'   => esc_html__('Widgets added here will appear on the right hand side from the mobile logo', 'optimize')
            ));
        }
    }

    add_action('widgets_init', 'optimize_mikado_register_mobile_header_areas');
}

if(!function_exists('optimize_mikado_register_sticky_header_areas')) {
    /**
     * Registers widget area for sticky header
     */
    function optimize_mikado_register_sticky_header_areas() {
        if(in_array(optimize_mikado_options()->getOptionValue('header_behaviour'), array('sticky-header-on-scroll-up','sticky-header-on-scroll-down-up'))) {
            register_sidebar(array(
                'name'          => esc_html__('Sticky Right', 'optimize'),
                'id'            => 'mkdf-sticky-right',
                'before_widget' => '<div id="%1$s" class="widget %2$s mkdf-sticky-right-widget"><div class="mkdf-sticky-right-widget-inner">',
                'after_widget'  => '</div></div>',
                'description'   => esc_html__('Widgets added here will appear on the right hand side in sticky menu', 'optimize')
            ));
        }
    }

    add_action('widgets_init', 'optimize_mikado_register_sticky_header_areas');
}