<?php

if(!function_exists('mkd_core_get_portfolio_item_overlay_styles')) {
    function mkd_core_get_portfolio_item_overlay_styles() {
	    $styles        = array();
	    $overlay_color = get_post_meta(get_the_ID(), 'portfolio_overlay_color', true);

	    if($overlay_color !== '') {
		    $styles[] = 'background-color: '.$overlay_color;
	    }

	    return $styles;
    }
}