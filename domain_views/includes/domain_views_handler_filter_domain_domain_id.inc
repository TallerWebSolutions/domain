<?php
// $Id$

/**
 * @file
 * Interface between domain_views.module and views.module.
 */

/**
 * Filter for domain ids stored in the database, currently active domain and any domain
 */
class domain_views_handler_filter_domain_domain_id extends views_handler_filter_in_operator  {
  function get_value_options() {
    if (!isset($this->value_options)) {
      $this->value_title = t('Domain');
      $domain_options = array('-1' => t('Any domain -- use with "Is not one of"'), '***CURRENT_DOMAIN***' => t('Current Domain'));
      $domains = domain_domains();
      foreach ($domains as $domain) {
        $domain_options[$domain['domain_id']] = $domain['sitename'];
        }
      $this->value_options = $domain_options;
    }
  }
}