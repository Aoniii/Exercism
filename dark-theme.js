// ==UserScript==
// @name         Exercism Dark Theme
// @namespace    https://github.com/Aoniii
// @version      1.0
// @description  Force dark theme on Exercism
// @match        https://exercism.org/*
// @run-at       document-start
// @grant        none
// ==/UserScript==

(function () {
    'use strict';

    const forceDark = () => {
        const body = document.body;
        if (!body) return;
        if (!body.classList.contains('theme-dark')) {
            body.classList.remove('theme-light', 'theme-system');
            body.classList.add('theme-dark');
        }
    };

    new MutationObserver(forceDark).observe(document.documentElement, {
        childList: true,
        subtree: true,
        attributes: true,
        attributeFilter: ['class'],
    });

    forceDark();
})();
