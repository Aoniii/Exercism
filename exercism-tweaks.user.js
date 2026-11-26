// ==UserScript==
// @name         Exercism Tweaks
// @namespace    https://github.com/Aoniii
// @version      1.0
// @description  Force the dark theme on Exercism and hide the donation banner and perk ads
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

    const hideAnnouncementBar = () => {
        document.querySelectorAll('.announcement-bar').forEach((el) => {
            if (el.classList.contains('md:block')) el.classList.remove('md:block');
        });
    };

    const hidePerkAds = () => {
        document.querySelectorAll('.c-perk-a').forEach((el) => {
            const target = el.closest('.lg-container') ?? el;
            if (!target.classList.contains('hidden')) target.classList.add('hidden');
        });
    };

    const apply = () => {
        forceDark();
        hideAnnouncementBar();
        hidePerkAds();
    };

    new MutationObserver(apply).observe(document.documentElement, {
        childList: true,
        subtree: true,
        attributes: true,
        attributeFilter: ['class'],
    });

    apply();
})();
